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

	} while (Number <= 0 );

	return Number;
}

float CalculateSeconds_By_Seconds(float NumberOfSeconds)
{
	return (float)NumberOfSeconds * 1;
}

float CalculateSeconds_By_Minutes(float NumberOfMinutes)
{
	return (float)NumberOfMinutes * 60;
}

float CalculateSeconds_By_Hours(float NumberOfHours)
{
	return (float)NumberOfHours * 60 * 60;
}

float CalculateSeconds_By_Days(float NumberOfDays)
{
	return (float)NumberOfDays * 24 * 60 * 60;
}

void PrintTaskDurationInSeconds(float NumberOfSeconds, float NumberOfMinutes, float NumberOfHours, float NumberOfDays)
{

	float Total = CalculateSeconds_By_Seconds(NumberOfSeconds) + CalculateSeconds_By_Minutes(NumberOfMinutes) +
		CalculateSeconds_By_Hours(NumberOfHours) + CalculateSeconds_By_Days(NumberOfDays);

	cout << "\n" << "Task Duration in Seconds = " << Total << " seconds " << endl;

}


int main()
{
	float NumberOfSeconds = ReadPositiveNumber("Please enter Number Of Seconds ?");
	float NumberOfMinutes = ReadPositiveNumber("Please enter Number Of Minutes ?");
	float NumberOfHours = ReadPositiveNumber("Please enter Number Of Hours ?");
	float NumberOfDays = ReadPositiveNumber("Please enter Number Of Days ?");

	PrintTaskDurationInSeconds(NumberOfSeconds, NumberOfMinutes, NumberOfHours, NumberOfDays);

    return 0;
}

