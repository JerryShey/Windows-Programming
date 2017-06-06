/******************************
4103056035 周彤 第六次作業12/21
******************************/
#pragma once

#include <fstream>
#include <cctype>					// For the isdigit() function
#include <cstring>					// For the strcpy() function
#include <math.h>					// For the log2(), log10(), power(), sqrt() function
#include <string>

void eatspaces(char* str);			 	// Function to eliminate blanks
double* expr(char* str);					// Function evaluating an expression
double* term(char* str, int& index);		// Function analyzing a term
double* number(char* str, int& index);	// Function to recognize a number
char* extract(char* str, int& index);	// Function to extract a substring
bool checkisdigit(wchar_t);

const int MAX(80);						// Maximum expression length, 
// including '\0'