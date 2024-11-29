#include <iostream>
using namespace std;

enum enDates { Before = 1, Equal = 2, After =3 };

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
		Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
			Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
	//return (Date1.Day == Date2.Day && Date1.Month == Date2.Month && Date1.Year == Date2.Year);
	return ((Date1.Day == Date2.Day) ? ((Date1.Month == Date2.Month) ? (Date1.Year == Date2.Year) ? true : false : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}

enDates DifferenceBetweenDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2)) 
		return enDates::Before;

	if (IsDate1EqualToDate2(Date1, Date2))
		return enDates::Equal;

	if (IsDate1AfterDate2(Date1, Date2))
		return enDates::After;
}

short CompareDates(enDates Dates)
{
	switch (Dates)
	{
	case enDates::Before:
		return -1;

	case enDates::Equal:
		return 0;

	case enDates::After:
		return 1;
	}
}

int main()
{
	system("color 5f");

	stDate Date1, Date2;

	cout << "\nEnter Date1: ";
	Date1 = ReadFullDate();

	cout << "\nEnter Date2: ";
	Date2 = ReadFullDate();

	cout << "\nCompare Result = " << CompareDates(DifferenceBetweenDates(Date1, Date2)) << endl;


	system("pause>0");
	return 0;
}