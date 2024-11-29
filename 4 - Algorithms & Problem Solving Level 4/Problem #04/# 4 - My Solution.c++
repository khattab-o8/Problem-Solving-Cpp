#include <iostream>
#include <string>
using namespace std;

struct stYearDuration
{
	int Days = 0;
	int Hours = 0;
	int Minutes = 0;
	int Seconds = 0;
};

short ReadYear()
{
	short Year = 0;
	cout << "\nPlease Enter a year to check? ";
	cin >> Year;

	return Year;
}

bool IsLeapYear(short Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

int CalculateNumberOfDays(short Year)
{
	int NumOfDays = 0;

	if (IsLeapYear(Year))
	{
		NumOfDays = 366;
		return NumOfDays;
	}
	else
	{
		NumOfDays = 365;
		return NumOfDays;
	}
}

stYearDuration Calculate_Days_Hours_Min_Sec(short Year)
{
	int NumOfDays = CalculateNumberOfDays(Year);
	stYearDuration InputTime;

	InputTime.Days = NumOfDays;
	InputTime.Hours = InputTime.Days * 24;
	InputTime.Minutes = InputTime.Hours * 60;
	InputTime.Seconds = InputTime.Minutes * 60;

	return InputTime;
}

void PrintOutPut(short Year, stYearDuration InputTime)
{
	cout << "\n\n";

	cout << "Number of Days    in Year [" << Year << "] is : " << InputTime.Days << " days." << endl;
	cout << "Number of Hours   in Year [" << Year << "] is : " << InputTime.Hours << " hours." << endl;
	cout << "Number of Minutes in Year [" << Year << "] is : " << InputTime.Minutes << " minutes." << endl;
	cout << "Number of Seconds in Year [" << Year << "] is : " << InputTime.Seconds << " seconds." << endl;
}

int main()
{
	system("color 5f");

	short Year = ReadYear();

	PrintOutPut(Year, Calculate_Days_Hours_Min_Sec(Year));


	system("pause>0");
	return 0;
}