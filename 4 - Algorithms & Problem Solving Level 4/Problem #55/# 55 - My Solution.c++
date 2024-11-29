#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

short ReadDay(string Massage)
{
	short Day;
	cout << "\n" << Massage;
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;
	Date.Day = ReadDay("Please enter a Day? ");
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = 0;
	DayIndex = DayOfWeekOrder(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

stDate CalculateVacationReturnDate(stDate StartDate, short VacationDays)
{
	short WeekEndDays = 0;

	while (IsWeekEnd(StartDate))
	{
		StartDate = IncreaseDateByOneDay(StartDate);
	}

	for (short i = 1; i <= VacationDays + WeekEndDays; i++)
	{
		if (IsWeekEnd(StartDate))
			WeekEndDays++;

		StartDate = IncreaseDateByOneDay(StartDate);
	}

	while (IsWeekEnd(StartDate))
	{
		StartDate = IncreaseDateByOneDay(StartDate);
	}

	return StartDate;
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	stDate StartDate, ReturnDate;
	short VacationDays = 0;

	cout << "Vacation Starts : ";
	StartDate = ReadFullDate();

	VacationDays = ReadDay("Please enter vacation days? ");

	ReturnDate = CalculateVacationReturnDate(StartDate, VacationDays);


	SetConsoleTextAttribute(h, 3);
	cout << "\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate))
	<< " , " << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year << "\n";


	system("pause>0");
	return 0;
}