#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
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
	if (IsLastDayInMonth(Date)) {

		if (IsLastMonthInYear(Date.Month)) {

			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else {

			Date.Day = 1;
			Date.Month++;
		}
	}
	else {

		Date.Day++;
	}
	return Date;
}

stDate IncreaseDateByX_Days(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

stDate IncreaseDateByX_Weeks(short weeks, stDate Date)
{
	for (short i = 1; i <= weeks; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 12) {
		Date.Month = 1;
		Date.Year++;
	}
	else {
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth =
		NumberOfDaysInAMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth) {

		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByX_Months(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;
	return Date;
}

stDate IncreaseDateByX_Years(short Years, stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByX_YearsFaster(short Years,stDate Date)
{
	Date.Year += Years;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date.Year += 10;
	return Date;
}

stDate IncreaseDateByX_Decades(short Decades, stDate Date)
{
	for (short i = 1; i <= Decades * 10; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate IncreaseDateByX_DecadesFaster(short Decades,stDate Date)
{
	Date.Year += Decades * 10;
	return Date;
}

stDate IncreaseDateByoneCentury(stDate Date)
{
	Date.Year += 100;
	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;
	return Date;
}

void PrintDateAfterUpdate()
{
	stDate Date = ReadFullDate();

	cout << "\nDate After:";

	cout << "\n____________________________________________\n";

	Date = IncreaseDateByOneDay(Date);
	cout << setw(35) << left << "\n01-Adding one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_Days(10, Date);
	cout << setw(35) << left << "\n02-Adding 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneWeek(Date);
	cout << setw(35) << left << "\n03-Adding one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_Weeks(10, Date);
	cout << setw(35) << left << "\n04-Adding 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneMonth(Date);
	cout << setw(35) << left << "\n05-Adding one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_Months(5, Date);
	cout << setw(35) << left << "\n06-Adding 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneYear(Date);
	cout << setw(35) << left << "\n07-Adding one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_Years(10, Date);
	cout << setw(35) << left << "\n08-Adding 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_YearsFaster(10,Date);
	cout << setw(35) << left << "\n09-Adding 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneDecade(Date);
	cout << setw(35) << left << "\n10-Adding one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_Decades(10, Date);
	cout << setw(35) << left << "\n11-Adding 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByX_DecadesFaster(10,Date);
	cout << setw(35) << left << "\n12-Adding 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByoneCentury(Date);
	cout << setw(35) << left << "\n13-Adding one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = IncreaseDateByOneMillennium(Date);
	cout << setw(35) << left << "\n14-Adding one Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n____________________________________________\n";

}

int main()
{
	system("color 5f");

	PrintDateAfterUpdate();

	system("pause>0");
	return 0;
}