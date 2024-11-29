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

stDate DecreaseDateByOneDay(stDate Date)
{
	if (Date.Day == 1) {

		if (Date.Month == 1) {

			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else {

			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}
	}
	else {

		Date.Day--;
	}

	return Date;

}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	for (short i = 1; i <= 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	if (Date.Month == 1) {

		Date.Month = 12;
		Date.Year--;
	}
	else {
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth =
		NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth) {

		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonths(short Months, stDate Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	for (short i = 1; i <= 12; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByXYears(short Years,stDate Date)
{
	for (short i = 1; i <= Years; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(short Decades,stDate Date)
{
	for (short i = 1; i <= Decades; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decades, stDate Date)
{
	Date.Year -= Decades * 10;

	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;

	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;

	return Date;
}

void PrintDateAfterUpdate()
{
	system("color 5f");

	stDate Date = ReadFullDate();
	cout << "\n_________________________________________________\n\n";

	cout << "\t\t** Date After: **";

	cout << "\n_________________________________________________\n";
	cout << "\a";

	Date = DecreaseDateByOneDay(Date);
	cout << setw(40) << left << "\n01-Subtracting one day is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDays(10,Date);
	cout << setw(40) << left << "\n02-Subtracting 10 days is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneWeek(Date);
	cout << setw(40) << left << "\n03-Subtracting one week is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXWeeks(10, Date);
	cout << setw(40) << left << "\n04-Subtracting 10 weeks is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMonth(Date);
	cout << setw(40) << left << "\n05-Subtracting one month is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXMonths(5, Date);
	cout << setw(40) << left << "\n06-Subtracting 5 months is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneYear(Date);
	cout << setw(40) << left << "\n07-Subtracting one year is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYears(10, Date);
	cout << setw(40) << left << "\n08-Subtracting 10 years is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << setw(40) << left << "\n09-Subtracting 10 years (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneDecade(Date);
	cout << setw(40) << left << "\n10-Subtracting one Decade is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecades(10, Date);
	cout << setw(40) << left << "\n11-Subtracting 10 Decades is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << setw(40) << left << "\n12-Subtracting 10 Decades (faster) is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneCentury(Date);
	cout << setw(40) << left << "\n13-Subtracting one Century is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	Date = DecreaseDateByOneMillennium(Date);
	cout << setw(40) << left << "\n14-Subtracting one Millennium is: " << Date.Day << "/" << Date.Month << "/" << Date.Year;

	cout << "\n_________________________________________________\n";

}

int main()
{
	PrintDateAfterUpdate();

	system("pause>0");
	return 0;
}