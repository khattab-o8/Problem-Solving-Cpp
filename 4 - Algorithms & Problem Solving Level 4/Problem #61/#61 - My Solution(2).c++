#include <iostream>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month ==
		Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false)
		: false;
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
	return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
		days[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month,
		Date.Year));
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

short ReadDay()
{
	short Day;
	cout << "\nPlease enter a Day? ";
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
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

stPeriod ReadPeriod()
{
	stPeriod Period;
	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();
	return Period;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

short CalculateOverlapDays(stPeriod Period1, stPeriod Period2, bool IncludeEndDay = false)
{
	if (CompareDates(Period1.StartDate, Period2.StartDate) == enDateCompare::After && CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::After && CompareDates(Period1.EndDate, Period2.EndDate) == enDateCompare::After)
		return GetDifferenceInDays(Period1.StartDate, Period2.EndDate, IncludeEndDay);

	if (CompareDates(Period2.StartDate, Period1.StartDate) == enDateCompare::After && CompareDates(Period1.EndDate, Period2.StartDate) == enDateCompare::After && CompareDates(Period2.EndDate, Period1.EndDate) == enDateCompare::After)
		return GetDifferenceInDays(Period2.StartDate,Period1.EndDate, IncludeEndDay);

	if (CompareDates(Period2.StartDate, Period1.StartDate) == enDateCompare::After && CompareDates(Period2.EndDate, Period2.StartDate) == enDateCompare::After && CompareDates(Period1.EndDate, Period2.EndDate) == enDateCompare::After)
		return GetDifferenceInDays(Period2.StartDate,Period2.EndDate, IncludeEndDay);

	if (CompareDates(Period1.StartDate, Period2.StartDate) == enDateCompare::After && CompareDates(Period1.EndDate,Period1.StartDate) == enDateCompare::After && CompareDates(Period2.EndDate,Period1.EndDate) == enDateCompare::After)
		return GetDifferenceInDays(Period1.StartDate,Period1.EndDate, IncludeEndDay);

	if (CompareDates(Period1.StartDate, Period2.EndDate) == enDateCompare::Equal || CompareDates(Period1.EndDate,Period2.StartDate) == enDateCompare::Equal)
		return 1;

	return 0;
}

int main()
{
	stPeriod Period1, Period2;

	cout << "\nEnter Period 1 :";
	Period1 = ReadPeriod();

	cout << "\nEnter Period 2 :";
	Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " << CalculateOverlapDays(Period1, Period2);

	system("pause>0");
	return 0;
}