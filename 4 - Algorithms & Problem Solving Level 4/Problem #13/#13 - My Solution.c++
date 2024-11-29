#include <iostream>
#include <string>
using namespace std;

short ReadDay()
{
	short Day = 0;
	do
	{
		cout << "\nPlease enter a Day ? ";
		cin >> Day;

	} while (Day < 1 || Day > 31);

	return Day;
}

short ReadMonth()
{
	short Month = 0;
	do
	{
		cout << "\nPlease enter a Month ? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadYear()
{
	short Year = 0;
	
	cout << "\nPlease enter a Year ? ";
	cin >> Year;

	return Year;
}

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12) {
		return 0;
	}

	short NumberOfDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromTheBeginingOfYear(short Day,short Month, short Year)
{
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	TotalDays += Day;
	return TotalDays;
}

bool check2Dates(sDate Date1, sDate Date2)
{
	if (Date1.Year > Date2.Year){
		return false;
	}

	if (NumberOfDaysFromTheBeginingOfYear(Date1.Day, Date1.Month, Date1.Year)
	> NumberOfDaysFromTheBeginingOfYear(Date2.Day, Date2.Month, Date2.Year)){
		return false;
	}

	return true;
}

int main()
{
	sDate Date1, Date2;

	Date1 = ReadFullDate();
	cout << "\n";
	Date2 = ReadFullDate();

	if (check2Dates(Date1, Date2)){
		cout << "\nYes, Date1 is Less than Date2.\n";
	}
	else{
		cout << "\nNo, Date1 is NOT Less than Date2.\n";
	}

	system("pause>0");
	return 0;
}