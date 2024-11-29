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

short NumberOfDaysToAdd()
{
	short TotalDays = 0;
	cout << "\nHow many days to add? ";
	cin >> TotalDays;

	return TotalDays;
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

short CalculateRemainingDaysByDicountGivenMonthdays(short DaysOrderInYear, short Day, short Month, short Year)
{
	return DaysOrderInYear - (NumberOfDaysInMonth(Month, Year) - Day);
}

sDate GetDateFromDaysOrderInYear(short DaysOrderInYear, short Day, short Month,short Year)
{
	sDate Date;

	short RemainingDays = CalculateRemainingDaysByDicountGivenMonthdays(DaysOrderInYear, Day, Month, Year);
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = Month + 1;

	while (true) //infinit while_loop.
	{
		MonthDays = NumberOfDaysInMonth(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;

			if (Date.Month == 12) {
				Date.Month = 0;
				Date.Year += 1;
			}
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
	short DaysOrderInYear = NumberOfDaysToAdd();

	sDate Date;
	Date = GetDateFromDaysOrderInYear(DaysOrderInYear, Day, Month, Year);

	cout << "\nDate after adding [" << DaysOrderInYear << "] days is: " << Date.Day
		<< "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
	return 0;
}