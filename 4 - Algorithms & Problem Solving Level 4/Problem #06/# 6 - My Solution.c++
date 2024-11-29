#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;

	cout << "\nPlease Enter a Month to check? ";
	cin >> Month;

	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return (IsLeapYear(Year)) ? 29 : 28;
	
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
		return 31;
	else
		return 30;
}

short NumberOfHoursInAMonth(short Month, short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}

int NumberOfMinutesInAMonth(short Month, short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}

int NumberOfSecondsInAMonth(short Month, short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

void PrintOutPut(short Month, short Year)
{
	cout << "\n";

	cout << "Number of Days    in Month [" << Month << "] is : " << NumberOfDaysInAMonth(Month, Year) << " days." << "\n";
	cout << "Number of Hours   in Month [" << Month << "] is : " << NumberOfHoursInAMonth(Month, Year) << " hours." << "\n";
	cout << "Number of Minutes in Month [" << Month << "] is : " << NumberOfMinutesInAMonth(Month, Year) << " minutes." << "\n";
	cout << "Number of Seconds in Month [" << Month << "] is : " << NumberOfSecondsInAMonth(Month, Year) << " seconds." << "\n";
}

int main()
{
	system("color 5f");

	short Year = ReadYear();
	short Month = ReadMonth();

	PrintOutPut(Month, Year);

	system("pause>0");
	return 0;
}