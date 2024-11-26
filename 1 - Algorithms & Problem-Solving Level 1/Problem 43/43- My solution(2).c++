#include <iostream>
#include <string>
using namespace std;

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

struct stTimeDuration
{
	int Days, Hours, Minutes, Seconds;
};

stTimeDuration TotalSeconds()
{
	stTimeDuration TimeDuration;

	TimeDuration.Seconds = ReadPositiveNumber("Please enter total Seconds ?");

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;
	int Remainder = 0;

	TimeDuration.Days = floor (TimeDuration.Seconds / SecondsPerDay);
	Remainder = TimeDuration.Seconds % SecondsPerDay;

	TimeDuration.Hours = floor(Remainder / SecondsPerHour);
	Remainder = Remainder % SecondsPerHour;

	TimeDuration.Minutes = floor(Remainder / SecondsPerMinute);
	Remainder = Remainder % SecondsPerMinute;

	TimeDuration.Seconds = Remainder;

	return TimeDuration;

}

void Printresult(stTimeDuration TimeDuration)
{
	cout << "\n" << TimeDuration.Days << ":" << TimeDuration.Hours << ":" <<
		TimeDuration.Minutes << ":" << TimeDuration.Seconds << endl;
}

int main()
{

	Printresult(TotalSeconds());

	return 0;
}

