#include <iostream>
#include <string>
using namespace std;

float ReadPositiveNumber(string Massage)
{
    float Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float CalculateDays(float NumberOfHours)
{
	float Days = 0;
	Days = NumberOfHours / 24;

	return Days;
}

float CalculateWeeks(float Days)
{
	float Weeks = 0;
	Weeks = Days / 7;

	return Weeks;
}


int main()
{
	float NumberOfHours = ReadPositiveNumber("Please enter Number Of Hours ?");
	float Days = CalculateDays(NumberOfHours);

	cout << "\n" << "Days = " << CalculateDays(NumberOfHours)<< " days" << endl;
	cout << "Weeks = " << CalculateWeeks(Days) << " weeks" << endl;

    return 0;
}

