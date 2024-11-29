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

struct sDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

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
	short TotalDays = 0;

	for (short i = 1; i < Month; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}

	return TotalDays + Day;
}

sDate GetDateFromDaysOrderInYear(short DaysOrderInYear, short Year)
{
	sDate Date;

	short RemainingDays = DaysOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true) //infinit while_loop.
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

int main()
{
	system("color 4f");

	short Day = ReadDay();
	short Month = ReadMonth();
	short Year = ReadYear();
	short DaysOrderInYear = NumberOfDaysFromBeginingOfYear(Day, Month, Year);

	cout << "\nNumber of Days from the begining of the year is : " << DaysOrderInYear << " days." << endl;

	sDate Date;
	Date = GetDateFromDaysOrderInYear(DaysOrderInYear, Year);

	cout << "\nDate for [" << DaysOrderInYear << "] is: " << Date.Day
		<< "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
	return 0;
}