#include <iostream>
#include <string>
#include <iomanip>
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

	} while (Month < 1 || Month > 21);

	return Month;
}

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a year ? ";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfDaysFromBeginingOfYear(short Day, short Month, short Year)
{
	short Sum = 0;

	for (short i = 1; i < Month; i++)
	{
		Sum += NumberOfDaysInMonth(i, Year);
	}

	return Sum + Day;
}


int main()
{
	system("color 4f");

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short Sum = NumberOfDaysFromBeginingOfYear(Day, Month, Year);

	cout << "\nNumber of Days from the begining of the year is : " << Sum << " days." << endl;

	system("pause>0");
	return 0;
}