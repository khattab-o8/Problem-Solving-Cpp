#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
	short Year = 0;
	cout << "Please Enter a year ? ";
	cin >> Year;

	return Year;
}

short ReadMonth()
{
	short Month = 0;
	do
	{
		cout << "\nPlease Enter a Month ? ";
		cin >> Month;

	} while (Month < 1 || Month > 12);

	return Month;
}

short ReadDay()
{
	short Day = 0;
	do
	{
		cout << "\nPlease Enter a Day ? ";
		cin >> Day;

	} while (Day < 1 || Day > 31);

	return Day;
}

short Calculate_a(short Month)
{
	short a = 0;

	a = (14 - Month) / (12);

	return a;
}

short Calculate_y(short a, short Year)
{
	short y = 0;

	y = Year - a;

	return y;
}

short Calculate_m(short a, short Month)
{
	short m = 0;

	m = Month + (12 * a) - 2;

	return m;
}

short CalculateGregorianCalender_d(short m, short y, short Day)
{
	short  d = 0 , y_4 = 0 ,  y_100 = 0  ,  y_400 = 0  ,  M = 0;

	y_4 = (y / 4);    y_100 = (y / 100);   y_400 = (y / 400);   M = (31 * m) / 12;

	d = (Day + y + y_4 - y_100 + y_400 + M) % 7;

	return d;
}

int main()
{
	system("color 5f");

	string DaysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	short a = Calculate_a(Month);
	short y = Calculate_y(a, Year);
	short m = Calculate_m(a, Month);
	short d = CalculateGregorianCalender_d(m, y, Day);

	cout << "\n\n";
	cout << "Date       : " << Day << "/" << Month << "/" << Year << "\n";
	cout << "Day Order  : " << d << "\n";
	cout << "Day Name   : " << DaysOfWeek[d] << "\n";


	system("pause>0");
	return 0;
}