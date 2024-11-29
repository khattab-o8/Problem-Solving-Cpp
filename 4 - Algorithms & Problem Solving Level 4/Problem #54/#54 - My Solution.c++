#include <iostream>
#include <string>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
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

bool IsWeekEnd(stDate Date)
{
	short DayIndex = 0;
	DayIndex = DayOfWeekOrder(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

short CalculateWeekEndDays(stDate StartDate, stDate EndDate)
{
	short Days = 0;

	while (IsDate1BeforeDate2(StartDate, EndDate))
	{
		if (IsWeekEnd(StartDate)) {

			Days++;
		}

		StartDate = IncreaseDateByOneDay(StartDate);
	}

	return Days;
}

short ActualVacationDays(stDate StartDate, stDate EndDate)
{
	return GetDifferenceInDays(StartDate, EndDate) - 
		CalculateWeekEndDays(StartDate, EndDate);
}


int main()
{
	stDate StartDate, EndDate;

	cout << "Vacation Starts : ";
	StartDate = ReadFullDate();

	cout << "\nVacation Ends : ";
	EndDate = ReadFullDate();

	cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(StartDate)) << 
	" , " << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year;

	cout << "\nVacation To: " << DayShortName(DayOfWeekOrder(EndDate)) <<
	" , " << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year;


	cout << "\n\nActual Vacation Days is: " << ActualVacationDays(StartDate, EndDate) << endl;


	system("pause>0");
	return 0;
}