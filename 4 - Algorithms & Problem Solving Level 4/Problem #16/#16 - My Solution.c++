#include <iostream>
#include <string>
using namespace std;

struct stDate
{
	short Year;
	short Month;
	short Day;
};

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
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
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

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastMonthInYear(Date.Month)) {

		if (IsLastDayInMonth(Date)) {
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Day++;
		}
	}
	else {
		if (IsLastDayInMonth(Date)) {
			Date.Day = 1;
			Date.Month++;
		}
		else{
			Date.Day++;
		}
	}

	return Date;
}

int main()
{
	stDate Date = ReadFullDate();
	Date = IncreaseDateByOneDay(Date);

	cout << "\nDate after adding One day is : " << Date.Day
	<< "/" << Date.Month << "/" << Date.Year << endl;

	system("pause>0");
	return 0;
}