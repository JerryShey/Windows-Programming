/******************************
4103056035 周彤 第七次作業12/30
******************************/
#include "stdafx.h"
#include "myMath.h"

void calc(array<System::Char>^ line, int^ price){
	int^ i = gcnew int(0);
	bool^ isDigit = gcnew bool(true);
	int^ result = gcnew int(0);

	for (*i; *i<(line->Length) && isDigit; (*i)++){
		if (!(line[(*i)] >= '0'&&line[(*i)] <= '9')){
			*isDigit = false;
			continue;
		}
		*result = (*result) * 10 + (line[*i] - '0');
	}
	*price = *result;
	delete i;
	delete isDigit; delete result;
}

int calcday(System::DateTime startday, System::DateTime endday){
	if (startday.Year == endday.Year){
		if (startday.Month == endday.Month){
			return endday.Day - startday.Day;
		}
		else{
			int months = endday.Month - startday.Month;
			int result = 0;
			result += startday.DaysInMonth(startday.Year, startday.Month) - startday.Day;
			for (int i = 1; i < months; i++){
				result += startday.DaysInMonth(startday.Year, startday.Month + i);
			}
			result += endday.Day;
		}
	}
	else{
		int result = 0;
		int years = endday.Year-startday.Year;
		result += startday.DaysInMonth(startday.Year, startday.Month) - startday.Day;
		for (int i = startday.Month+1; i <= 12; i++){
			result += startday.DaysInMonth(startday.Year, i);
		}
		for (int i = 1; i < years; i++){
			if (startday.IsLeapYear(startday.Year + i))
				result += 366;
			else
				result += 365;
		}
		for (int i = 1; i <= endday.Month; i++){
			result += endday.DaysInMonth(endday.Year, i);
		}
		result += endday.Day;
		return result;
	}
	
}
