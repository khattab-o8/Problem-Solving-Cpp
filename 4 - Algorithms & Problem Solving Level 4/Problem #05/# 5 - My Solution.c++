#include <iostream>
#include <string>
using namespace std;

enum eYearMonths
{ Jan = 1, Feb = 2, Mar = 3, Apr = 4,
 May = 5, Jun = 6, July = 7, Aug = 8,
 Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;

	do
	{
		cout << "\nPlease Enter a Month to check? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAMonth(short Year, eYearMonths MonthofYear)
{
	switch (MonthofYear)
	{
	case eYearMonths::Jan:
		return 31;
		break;

	case eYearMonths::Feb:
		return (IsLeapYear(Year)) ? 29 : 28;
		break;

	case eYearMonths::Mar:
		return 31;
		break;

	case eYearMonths::Apr:
		return 30;
		break;

	case eYearMonths::May:
		return 31;
		break;

	case eYearMonths::Jun:
		return 30;
		break;

	case eYearMonths::July:
		return 31;
		break;

	case eYearMonths::Aug:
		return 31;
		break;

	case eYearMonths::Sep:
		return 30;
		break;

	case eYearMonths::Oct:
		return 31;
		break;

	case eYearMonths::Nov:
		return 30;
		break;

	case eYearMonths::Dec:
		return 31;
		break;
	}
}

short NumberOfHoursInAMonth(short Year, eYearMonths MonthofYear)
{
	return NumberOfDaysInAMonth(Year, MonthofYear) * 24;
}

int NumberOfMinutesInAMonth(short Year, eYearMonths MonthofYear)
{
	return NumberOfHoursInAMonth(Year, MonthofYear) * 60;
}

int NumberOfSecondsInAMonth(short Year, eYearMonths MonthofYear)
{
	return NumberOfMinutesInAMonth(Year, MonthofYear) * 60;
}

void PrintOutPut(short Year, eYearMonths MonthofYear)
{
	cout << "\n";

	cout << "Number of Days    in Month [" << MonthofYear << "] is : " << NumberOfDaysInAMonth(Year, MonthofYear) << " days." << "\n";
	cout << "Number of Hours   in Month [" << MonthofYear << "] is : " << NumberOfHoursInAMonth(Year, MonthofYear) << " hours." << "\n";
	cout << "Number of Minutes in Month [" << MonthofYear << "] is : " << NumberOfMinutesInAMonth(Year, MonthofYear) << " minutes." << "\n";
	cout << "Number of Seconds in Month [" << MonthofYear << "] is : " << NumberOfSecondsInAMonth(Year, MonthofYear) << " seconds." << "\n";
}

int main()
{
	system("color 5f");

	short Year = ReadYear();
	eYearMonths MonthofYear = (eYearMonths)ReadMonth();

	PrintOutPut(Year, MonthofYear);

	system("pause>0");
	return 0;
}