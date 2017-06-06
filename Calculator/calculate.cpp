/******************************
4103056035 周彤 第六次作業12/21
******************************/
#include "stdafx.h"
#include "calculate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool negative = false;

// Function to eliminate spaces from a string
void eatspaces(char* str){
	int* i = new int(0);							// 'Copy to' index to string
	int* j = new int(0);							// 'Copy from' index to string

	while ((*(str + (*i)) = *(str + (*j)++)) != '\0')  // Loop while character
		// copied is not \0
		if (*(str + (*i)) != ' ')			// Increment i as long as
			(*i)++;								// character is not a space
	return;
}

// Function to evaluate an arithmetic expression
double* expr(char* str){
	double* value = new double(0.0);					// Store result here
	double* value2 = new double(0.0);
	int* index = new int(0);						// Keeps track of current character position

	value = term(str, *index);            // Get first term

	for (;;)							// Indefinite loop, all exits inside
	{
		switch (*(str + (*index)++))           // Choose action based on current character
		{
		case '\0':					// We're at the end of the string
			delete value2;
			negative = false;
			return value;                 // so return what we have got

		case '+':						// + found so add in the
			value2 = term(str, *index);
			*(value) += *(value2);    // next term
			break;
		case '-':						// - found so subtract
			value2 = term(str, *index);
			*(value) -= *(value2);    // the next term
			break;
		}
		
	}
}

// Function to get the value of a term
double* term(char* str, int& index){
	double* value = new double(0.0);					// Somewhere to accumulate the result
	double* value2 = new double(0.0);
	value = number(str, index);          // Get the first number in the term

	// Loop as long as we have a good operator
	while (true){
		if (*(str + index) == '*'){	// If it's multiply,
			value2 = number(str, ++index);
			*(value) *= *(value2);	// multiply by next number
		}
		else if (*(str + index) == '/'){	// If it's divide,
			value2 = number(str, ++index);
			*(value) /= *(value2);	// divide by next number
		}

		else if (*(str + index) == '%'){
			value2 = term(str, ++index);
			(*value) = fmod((*value), *(value2));
		}

		else if (*(str + index) == 'E')	//	If it's a Scientific notation number
			if (*(str + (++index)) == '+'){	// If next op is '+', value mutiply by 10 n(next number) times
				double* n = number(str, ++index);
				for (int i = 0; i < *n; i++)
					(*value) *= 10;
				delete n;
			}
			else{
				double* n = number(str, ++index);
				for (int i = 0; i < *n; i++) // If next op is '-', value divide by 10 n(next number) times
					(*value) /= 10;
				delete n;
			}
		else if (*(str + index) == '^'){
			double* base = new double((*value));
			value = term(str, ++index);
			*(value) = pow(*base, (*value));
			delete base;
		}
		else if ((*(str + index) == '!')){	// If it's factorial
			int* i = new int((*value)-1);
			for (; (*i) > 0; (*i)--)
				(*value) *= (*i);
			delete i;
			index++;
		}

		else
			break;
	}
	delete value2;
	return value;				// We've finished, so return what 
	// we've got
}

// Function to recognize a number in a string
double* number(char* str, int& index){
	double* value = new double(0.0);					// Store the resulting value
	double* e = new double(2.71828);
	if (*(str + index) == '-')
		if (!negative){
			negative = !negative;
		}
	

	if (*(str + index) == '('){				// Start of parentheses
		char* psubstr(nullptr);				// Pointer for substring
		psubstr = extract(str, ++index);	// Extract substring in brackets
		value = expr(psubstr);				// Get the value of the substring
		delete[]psubstr;					// Clean up the free store
		delete e;
		if (negative)
			(*value) *= (-1);
		negative = false;
		return value;						// Return substring value
	}

	

	if (*(str + index) == 's'){
		char sqrt[5];
		int* i = new int(0);
		while ((*(sqrt + (*i)) = *(str + (index++))) != '('){
			(*i)++;
		}
		*(sqrt + (*i)) = '\0';


		double* x = new double(0.0);
		x = expr(str + (--index));

		if ((*x)<0){
			
		}
		index++;
		*value = sqrtf(*x);

		delete x;
		delete e;
		if (negative)
			(*value) *= (-1);
		negative = false;

		return value;
	}

	if (*(str + index) == 'l'){
		char logWord[6];
		int* i = new int(0);
		while ((*(logWord + (*i)) = *(str + (index++))) != '('){
			(*i)++;
		}
		*(logWord + (*i)) = '\0';
		double* x = new double(0.0);
		x = expr(str + (--index));
		index += strlen(extract(str, ++index)) + 2;
		if ((*x) <= 0){
			/*cout << "Something Wrong!!!" << endl;
			exit(1);*/
		}

		(*value) = log2f(*x);
		delete x;
		delete e;
		if (negative)
			(*value) *= (-1);
		negative = false;
		return value;
	}
	if (*(str + index) == 'e'){
		index++;
		return e;
	}

	// There must be at least one digit...
	if (!isdigit(*(str + index))){ // There's no digits so input is junk...
		/*cout << endl
			<< "Arrrgh!*#!! There's an error"
			<< endl;
		exit(1);*/
	}

	while (isdigit(*(str + index)))      // Loop accumulating leading digits
		*value = 10 * (*value) + (*(str + index++) - '0');

	// Not a digit when we get to here
	if (*(str + index) != '.'){			// so check for decimal point
		delete e;
		if (negative)
			(*value) *= (-1);
		negative = false;
		return value;					// and if not, return value
	}

	double factor(1.0);				// Factor for decimal places
	while (isdigit(*(str + (++index)))){	// Loop as long as we have digits
		factor *= 0.1;					// Decrease factor by factor of 10
		*(value) = *(value)+(*(str + index) - '0')*factor;   // Add decimal place
	}
	delete e;
	if (negative)
		(*value) *= (-1);
	negative = false;
	return value;						// On loop exit we are done
}

// Function to extract a substring between parentheses 
// (requires cstring)
char* extract(char* str, int& index){
	char buffer[MAX];					// Temporary space for substring
	char* pstr(nullptr);                // Pointer to new string for return
	int* numL = new int(0);						// Count of left parentheses found
	int* bufindex = new int(index);                // Save starting value for index
	
	do{
		buffer[index - *(bufindex)] = *(str + index);
		switch (buffer[index - *(bufindex)])
		{
		case ')':
			if (0 == (*numL)){
				size_t size = index - *(bufindex);
				buffer[index - *(bufindex)] = '\0';  // Replace ')' with '\0' 
				++index;
				pstr = new char[index - *(bufindex)];
				/*if (!pstr)
				{
					cout << "Memory allocation failed,"
						<< " program terminated.";
					exit(1);
				}*/
				strcpy_s(pstr, index - *(bufindex), buffer); // Copy substring to new memory
				return pstr;				// Return substring in new memory
			}
			else
				*(numL)--;					// Reduce count of '(' to be matched
			break;

		case '(':
			*(numL)++;					// Increase count of '('
			break;						// matched
		}
	} while (*(str + index++) != '\0'); // Loop - don't overrun end of strig;
	/*cout << "Ran off the end of the expression, must be bad input."
		<< endl;
	exit(1);*/
}

bool checkisdigit(wchar_t chk){
	if ((chk < 48 && chk != 41) || (chk > 57 && chk != 101))
		return false;
	return true;
}