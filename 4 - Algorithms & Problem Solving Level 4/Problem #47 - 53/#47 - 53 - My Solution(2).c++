#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
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

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}  // Function Overloading.

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

bool IsDate1BeforeDate2(stDate Date, stDate Date2)
{                                           
	return (Date.Year < Date2.Year) ? true : ((Date.Year == Date2.Year)?
	(Date.Month < Date2.Month) ? true : (Date.Month == Date2.Month)? 
	Date.Day < Date2.Day : false : false);
}

bool IsEndOfWeek(stDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekEnd(Date);  //Reusability Of Code.

	// Not false is true.
}

short DaysUntilTheEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate;

	TempDate.Year = Date1.Year;
	TempDate.Month = Date1.Month;
	TempDate.Day = Date1.Day;

	Date1.Year = Date2.Year;
	Date1.Month = Date2.Month;
	Date1.Day = Date2.Day;

	Date2.Year = TempDate.Year;
	Date2.Month = TempDate.Month;
	Date2.Day = TempDate.Day;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	short SawpFlagValue = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		//Swap Dates
		SwapDates(Date1, Date2);
		SawpFlagValue = -1;
	}
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

short DaysUntilTheEndOfMonth(stDate Date)
{
	stDate EndOfMonthDay;
	EndOfMonthDay.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDay.Month = Date.Month;
	EndOfMonthDay.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDay,true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
	stDate EndOfYearDate;

	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate,true);
}

void PrintCurrentDateDetails()
{
	stDate Date;	
	Date = GetSystemDate();

	cout << "\nToday is " << GetDayName(DayOfWeekOrder(Date)) << " , " << Date.Day <<
		"/" << Date.Month << "/" << Date.Year << "\n";

	//--------------------------------------------
	cout << "\n\n" << "Is it End of Week? \n";
	if (IsEndOfWeek(Date)){
		cout << "Yes, End of week.";
	}
	else {
		cout << "No, NOT End of week.";
	}

	//--------------------------------------------
	cout << "\n\n\n" << "Is it Weekend? \n";
	if (IsWeekEnd(Date)) {
		cout << "Yes, it is a week end.";
	}
	else {
		cout << "No, it is NOT a week end.";
	}

	//--------------------------------------------
	cout << "\n\n\n" << "Is it Business Day? \n";
	if (IsBusinessDay(Date)) {
		cout << "Yes, it is a business day.";
	}
	else {
		cout << "No, it is NOT a business day.";
	}

	//--------------------------------------------
	cout << "\n\n\n" << "Days until end of week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";

	cout << "\n" << "Days until end of month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";

	cout << "\n" << "Days until end of year : " << DaysUntilTheEndOfYear(Date) << " Day(s)." << endl;
}

int main()
{
	PrintCurrentDateDetails();

	system("pause>0");
	return 0;
}