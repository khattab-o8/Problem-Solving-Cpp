#include <iostream>
#include <string>
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

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0;
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return ((NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day) ? true : false);
}

bool IsLastMonthInYear(short Month)
{
	const short LastMonth = 12;

	return ((Month == LastMonth) ? true : false);
}

int main()
{
	system("color 4f");

	stDate Date = ReadFullDate();

	if (IsLastDayInMonth(Date))
		cout << "\nYes, Day is Last Day in Month.\n";
	else
		cout << "\nNo, Day is NOT the Last Day in Month.\n";

	if (IsLastMonthInYear(Date.Month))
		cout << "\nYes, Month is Last Month in Year.\n";
	else
		cout << "\nNo, Month is NOT the Last Month in Year.\n";


	system("pause>0");
	return 0;
}