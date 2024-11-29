#include <iostream>
#include <string>
using namespace std;

struct stDate
{
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

short ReadDay()
{
	short Day = 0;
	do
	{
		cout << "Please enter a Day ? ";
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
	cout << "\n\n";
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

bool IsLeepYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	return (Month == 2) ? ((IsLeepYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date1)
{
	return (Date1.Day == NumberOfDaysInMonth(Date1.Month, Date1.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneday(stDate Date1)
{
	if (IsLastDayInMonth(Date1)) {

		if (IsLastMonthInYear(Date1.Month)) {
			Date1.Day = 1;
			Date1.Month = 1;
			Date1.Year++;
		}
		else {
			Date1.Day = 1;
			Date1.Month++;
		}
	}
	else {
		Date1.Day++;
	}

	return Date1;
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false )
{
	int Days = 0;
	while (IsDate1LessThanDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneday(Date1);
	}

	return (IncludeEndDay) ? ++Days : Days;
}

int main()
{
	system("color 4f");
	stDate Date1, Date2;

	Date1 = ReadFullDate();
	Date2 = ReadFullDate();

	cout << "\nDifference is: " << GetDifferenceInDays(Date1, Date2) << " Day(s)." << endl;
	cout << "Difference (Including End Day) is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)." << endl;

	system("pause>0");
	return 0;
}