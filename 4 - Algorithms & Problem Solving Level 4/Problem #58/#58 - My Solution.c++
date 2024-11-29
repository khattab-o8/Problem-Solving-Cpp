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

bool IsOverLapPeriod(stPeriod Period1, stPeriod Period2)
{
	return ((IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate)) ? ((!IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
		? ((IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate)) ? ((!IsDate1EqualDate2(Period1.EndDate, Period2.StartDate)) ?
			((IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate)) ? true : false) : false) : false) : false) : false);
}

int main()
{
	system("color 5f");
	stPeriod Period1, Period2;

	cout << "Enter Period 1:\n";
	Period1 = ReadFullPeriod();

	cout << "\n\nEnter Period 2:\n";
	Period2 = ReadFullPeriod();

	if (IsOverLapPeriod(Period1, Period2)) {
		system("color 4f");
		cout << "\n\nNo, Periods are NOT Overlap.";
	}
	else {
		system("color 2f");
		cout << "\a";
		cout << "\n\nYes, Periods Overlap.";
	}

	system("pause>0");
	return 0;
}