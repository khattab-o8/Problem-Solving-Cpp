#include <iostream>
#include <string>
using namespace std;

struct stTime
{
	int Days = 0, Hours = 0,
		Minutes = 0, Seconds = 0;
};

int ReadPositiveNumber(string Massage)
{
    int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

stTime TransferSeconds(int EnteredSeconds)
{
	stTime iput;

	const int SecondsToDays = 24 * 60 * 60;
	const int SecondsToHours = 60 * 60;
	const int SecondsToMinutes = 60;

	iput.Days = EnteredSeconds / SecondsToDays;
	EnteredSeconds = EnteredSeconds % SecondsToDays;

	iput.Hours = EnteredSeconds / SecondsToHours;
	EnteredSeconds = EnteredSeconds % SecondsToHours;

	iput.Minutes = EnteredSeconds / SecondsToMinutes;
	EnteredSeconds = EnteredSeconds % SecondsToMinutes;

	iput.Seconds = EnteredSeconds;

	return iput;
}

void PrintOutPut(stTime iput)
{
	cout << "\n" << "Output :- " << endl;

	cout << "\n" << iput.Days << ":" << iput.Hours << ":"
		<< iput.Minutes << ":" << iput.Seconds << "\n\n";
}

int main()
{
	PrintOutPut(TransferSeconds(ReadPositiveNumber("Please enter Number Of Seconds ?")));

    return 0;
}