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

struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, RemainedSeconds;

};

strTaskDuration ReadTaskDuartion()
{
	strTaskDuration TaskDuration;

	return TaskDuration;
}

int TaskDurationInDays(strTaskDuration TaskDuration, int NumberOfSeconds)
{
	TaskDuration.NumberOfDays = floor(NumberOfSeconds / 60 / 60 / 24);

	return TaskDuration.NumberOfDays;
}

int TransferDaysToSeconds(strTaskDuration TaskDuration)
{
	int DaysToSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
	return DaysToSeconds;
}

int RemainderSeconds1(int NumberOfSeconds, int DaysToSeconds)
{
	int Remainder1 = NumberOfSeconds - DaysToSeconds;
	return Remainder1;
}

int TaskDurationInHours(strTaskDuration TaskDuration, int Remainder1)
{
	TaskDuration.NumberOfHours = floor (Remainder1 / 60 / 60);
	return TaskDuration.NumberOfHours;
}

int TransferHoursToSeconds(strTaskDuration TaskDuration)
{
	int HoursToSeconds = TaskDuration.NumberOfHours * 60 * 60;
	return HoursToSeconds;
}

int RemainderSeconds2(int HoursToSeconds, int Remainder1)
{
	int Remainder2 = Remainder1 - HoursToSeconds;
	return Remainder2;
}

int TaskDurationInMinutes(strTaskDuration TaskDuration, int Remainder2)
{
	TaskDuration.NumberOfMinutes = floor (Remainder2 / 60);
	return TaskDuration.NumberOfMinutes;
}

int TransferMinutesToSeconds(strTaskDuration TaskDuration)
{
	int MinutesToSeconds = TaskDuration.NumberOfMinutes * 60;
	return MinutesToSeconds;
}

int TaskDurationInSeconds(strTaskDuration TaskDuration,int MinutesToSeconds,int Remainder2)
{
	TaskDuration.RemainedSeconds = Remainder2 - MinutesToSeconds;
	return TaskDuration.RemainedSeconds;
}


int main()
{
	int NumberOfSeconds = ReadPositiveNumber("Please enter Number of Seconds ?");
	strTaskDuration TaskDuration = ReadTaskDuartion();
	int DaysToSeconds = TransferDaysToSeconds(TaskDuration);
	int Remainder1 = RemainderSeconds1(NumberOfSeconds, DaysToSeconds);
	int HoursToSeconds = TransferHoursToSeconds(TaskDuration);
	int Remainder2 = RemainderSeconds2(HoursToSeconds, Remainder1);
	int MinutesToSeconds = TransferMinutesToSeconds(TaskDuration);



	cout << "\nTask Duration in : - " << endl;
	cout << "*************************" << endl;
	cout << "Days = " << TaskDurationInDays(TaskDuration, NumberOfSeconds) << endl;
	cout << "Hours = " << TaskDurationInHours(TaskDuration, Remainder1) << endl;
	cout << "Minutes =  " << TaskDurationInMinutes(TaskDuration, Remainder2) << endl;
	cout << "Seconds = " << TaskDurationInSeconds(TaskDuration, MinutesToSeconds, Remainder2) << endl;

    return 0;
}

