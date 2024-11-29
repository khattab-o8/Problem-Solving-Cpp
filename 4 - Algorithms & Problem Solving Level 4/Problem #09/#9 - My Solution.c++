#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease enter a year ? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;
	cout << "\nPlease enter a Month ? ";
	cin >> Month;

	return Month;
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a = 0, y = 0, m = 0;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthName(short Month)
{
	string MonthOfYear[] =
	{ "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return MonthOfYear[Month];
}

void PrintWeekDays()
{
	string DaysOfWeek[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	for (short i = 0; i < 7; i++)
	{
		cout << "\t" << setw(5) << left << DaysOfWeek[i];
	}
	cout << endl;
}

void MonthCalendar(short Month, short Year)
{
	cout << "\n\n";

	short Current = DayOfWeekOrder(1, Month, Year);
	short NumberOfDays = NumberOfDaysInMonth(Month, Year);

	cout << "\t" << "________________________" << MonthName(Month) << "________________________" << "\n\n";
	PrintWeekDays();

	short i;
	for (i = 0; i < Current; i++)
	{
		cout << "\t" << setw(3) << right << " ";
	}

	for (short j = 1; j <= NumberOfDays; j++)
	{
		if (i == 7)
		{
			cout << endl;
			i = 0;
		}
		cout << "\t" << setw(3) << right << j;
		i++;
	}
	cout << endl;
	cout << "\t" << "___________________________________________________" << "\n";
}

void PrintYearCalendar(short Year)
{
	cout << "\n\n" << "\t" << "___________________________________________________" << "\n\n";
	cout << "\t\t" << "          CaLendar - " << Year << endl;
	cout << "\t" << "___________________________________________________" << "\n";


	for (short i = 1; i <= 12; i++)
	{
		MonthCalendar(i, Year);
	}
}

int main()
{
	system("color 4f");

	short Year = ReadYear();

	PrintYearCalendar(Year);


	system("pause>0");
	return 0;
}