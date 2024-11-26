#include <iostream>
#include <string>
using namespace std;

enum enMonthsOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, 
	Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

int ReadNumberInRange(string Massage, int From,int To)
{
    int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while ( Number < From || Number > To );

	return Number;
}

enMonthsOfYear ReadMonth()
{
	return (enMonthsOfYear)ReadNumberInRange("Please enter Month Number From ( 1 to 12 ) ?", 1, 12);
}

string GetMonthName(enMonthsOfYear Month)
{
	switch (Month)
	{
	case enMonthsOfYear::Jan:
		return "January";

	case enMonthsOfYear::Feb:
		return "February";

	case enMonthsOfYear::Mar:
		return "March";

	case enMonthsOfYear::Apr:
		return "April";

	case enMonthsOfYear::May:
		return "May";

	case enMonthsOfYear::Jun:
		return "June";

	case enMonthsOfYear::Jul:
		return "July";

	case enMonthsOfYear::Aug:
		return "August";

	case enMonthsOfYear::Sep:
		return "September";

	case enMonthsOfYear::Oct:
		return "October";

	case enMonthsOfYear::Nov:
		return "November";

	case enMonthsOfYear::Dec:
		return "December";

	default:
		return "\"Wrong Month\"";
	}

}

int main()
{
	cout << GetMonthName(ReadMonth()) << endl;

    return 0;
}

