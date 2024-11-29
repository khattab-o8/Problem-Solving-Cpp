#include <iostream>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

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

stPeriod ReadFullPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date:\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	//return (Date1.Day == Date2.Day && Date1.Month == Date2.Month && Date1.Year == Date2.Year);
	return ((Date1.Day == Date2.Day) ? ((Date1.Month == Date2.Month) ? (Date1.Year == Date2.Year) ? true : false : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
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

enum enDateCompare { Before = -1, Equal = 0, After = 1 };
enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;
	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;
	/* if (IsDate1AfterDate2(Date1,Date2))
	return enDateCompare::After;*/
	//this is faster
	return enDateCompare::After;
}

void SwapDates(stDate& Date1, stDate& Date2)
{
	stDate TempDate;

	TempDate.Day = Date1.Day;
	TempDate.Month = Date1.Month;
	TempDate.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = TempDate.Day;
	Date2.Month = TempDate.Month;
	Date2.Year = TempDate.Year;
}

short GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{     
	short Days = 0;
	short SwapFlagValue = 1;

	if (CompareDates(Date1, Date2) == enDateCompare::After) {

		SwapFlagValue = -1;
		SwapDates(Date1, Date2);
	}

	while (CompareDates(Date1, Date2) == enDateCompare::Before)
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return (IncludeEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int main()
{
	system("color 5f");
	stPeriod Period1;

	cout << "Enter Period 1:\n";
	Period1 = ReadFullPeriod();

	cout << "\nPeriod Length is: " <<
	GetDifferenceInDays(Period1.StartDate, Period1.EndDate);

	cout << "\nPeriod Length (Including End Date) is: " <<
	GetDifferenceInDays(Period1.StartDate, Period1.EndDate, true);


	system("pause>0");
	return 0;
}