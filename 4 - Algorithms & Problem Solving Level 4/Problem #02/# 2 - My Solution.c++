#include <iostream>
#include <string>
using namespace std;

enum eLeapNotLeap { LeapYear = 1, NotLeapYear = 2 };

int ReadNumber()
{
	int Num = 0;
	cout << "Please Enter Year Number ? \n";
	cin >> Num;

	return Num;
}

eLeapNotLeap CheckYear(int Number)
{
	if (Number % 100 == 0 && Number % 4 == 0)
	{
		if (Number % 400 == 0)
		{
			return eLeapNotLeap::LeapYear;
		}
		else
		{
			return eLeapNotLeap::NotLeapYear;
		}
	}

	if (Number % 4 == 0)
	{
		return eLeapNotLeap::LeapYear;
	}
	else
	{
		return eLeapNotLeap::NotLeapYear;
	}
}

void PrintResult(eLeapNotLeap LeapNotLeap)
{
	cout << "\n";

	switch (LeapNotLeap)
	{
	case eLeapNotLeap::LeapYear:
		cout << "Leap Year";
		break;

	case eLeapNotLeap::NotLeapYear:
		cout << "Not Leap Year";
		break;
	}
}

int main()
{
	system("color 5f");

	PrintResult(CheckYear(ReadNumber()));

	system("pause>0");
	return 0;
}