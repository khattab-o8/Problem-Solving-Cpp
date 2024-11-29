#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm* Now = localtime(&t);

	Date.Day = Now->tm_mday;
	Date.Month = Now->tm_mon + 1;
	Date.Year = Now->tm_year + 1900;

	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short DayOrder)
{
	string DayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return DayName[DayOrder];
}

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{                                           
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year)?
	(Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month)? 
	Date1.Day < Date2.Day : false : false);
}

bool IsEndOfWeek(string DayShortName)
{
	return (DayShortName == "Sat");
}

bool IsWeekEnd(string DayShortName)
{
	return (DayShortName == "Fri");
}

bool IsBusinessDay(string DayShortName)
{
	return (DayShortName != "Fri" && DayShortName != "Sat");
}

short DaysUntilTheEndOfWeek(stDate Date,string DayShortName)
{
	short Days = 0;

	while (!IsEndOfWeek(DayShortName))
	{
		Days++;
		Date = IncreaseDateByOneDay(Date);
		short DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		DayShortName = GetDayName(DayOrder);
	}

	return Days;
}

short DaysUntilTheEndOfMonth(stDate Date, bool NotIncludeEndDay = false)
{
	short NumberOfDaysInCurrentMonth = 0, Days = 0;

	NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	Days = NumberOfDaysInCurrentMonth - Date.Day;

	return (NotIncludeEndDay) ? ++Days : Days;
}

stDate GetEndOfYearDate(stDate Date1)
{
	stDate Dat2;
	Dat2.Day = 31;
	Dat2.Month = 12;
	Dat2.Year = Date1.Year;

	return Dat2;
}

short DaysUntilTheEndOfYear(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	short Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return (IncludeEndDay) ? ++Days : Days;
}

void PrintCurrentDateDetails()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	stDate Date1, Date2;
		
	Date1 = GetSystemDate();
	Date2 = GetEndOfYearDate(Date1);

	short DayOrder = DayOfWeekOrder(Date1.Day, Date1.Month, Date1.Year);
	string DayShortName = GetDayName(DayOrder);

	SetConsoleTextAttribute(h, 2);
	cout << "\nToday is " << DayShortName << " , " << Date1.Day <<
		"/" << Date1.Month << "/" << Date1.Year << "\n";

	SetConsoleTextAttribute(h, 4);
	cout << "\n\n" << "Is it End of Week? \n";
	if (IsEndOfWeek(DayShortName)){
		cout << "Yes, End of week.";
	}
	else {
		cout << "No, NOT End of week.";
	}

	SetConsoleTextAttribute(h, 6);
	cout << "\n\n\n" << "Is it Weekend? \n";
	if (IsWeekEnd(DayShortName)) {
		cout << "Yes, it is a week end.";
	}
	else {
		cout << "No, it is NOT a week end.";
	}

	SetConsoleTextAttribute(h, 5);
	cout << "\n\n\n" << "Is it Business Day? \n";
	if (IsBusinessDay(DayShortName)) {
		cout << "Yes, it is a business day.";
	}
	else {
		cout << "No, it is NOT a business day.";
	}

	SetConsoleTextAttribute(h, 3);
	cout << "\n\n\n" << "Days until end of week : " << DaysUntilTheEndOfWeek(Date1, DayShortName) << " Day(s).";

	cout << "\n" << "Days until end of month : " << DaysUntilTheEndOfMonth(Date1, true) << " Day(s).";

	cout << "\n" << "Days until end of year : " << DaysUntilTheEndOfYear(Date1, Date2, true) << " Day(s)." << endl;

}

int main()
{
	PrintCurrentDateDetails();

	system("pause>0");
	return 0;
}