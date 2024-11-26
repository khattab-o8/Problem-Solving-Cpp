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

		if (Number >= 1 && Number <= 7)
		{
			break;
		}

		cout << "\"Wrong Day !!\"" << endl;

	} while (Number < 1 || Number > 7);

	return Number;

}

enum enWeekDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

enWeekDays ReadDayNumber(int Day)
{
	if (Day == 1)
		return enWeekDays::Sunday;
	else if (Day == 2)
		return enWeekDays::Monday;
	else if (Day == 3)
		return enWeekDays::Tuesday;
	else if (Day == 4)
		return enWeekDays::Wednesday;
	else if (Day == 5)
		return enWeekDays::Thursday;
	else if (Day == 6)
		return enWeekDays::Friday;
	else if (Day == 7)
		return enWeekDays::Saturday;
}

void PrintDays(int Day)
{
	switch (ReadDayNumber(Day))
	{
	case enWeekDays::Sunday:
		cout << "It's Sunday" << endl;
			break;

	case enWeekDays::Monday:
		cout << "It's Monday" << endl;
		break;

	case enWeekDays::Tuesday:
		cout << "It's Tuesday" << endl;
		break;

	case enWeekDays::Wednesday:
		cout << "It's Wednesday" << endl;
		break;

	case enWeekDays::Thursday:
		cout << "It's Thursday" << endl;
		break;

	case enWeekDays::Friday:
		cout << "It's Friday:" << endl;
		break;

	case enWeekDays::Saturday:
		cout << "It's Saturday" << endl;
		break;

	}

}

int main()
{
	int Day = ReadPositiveNumber("Please enter Day Number ?");
	PrintDays(Day);

    return 0;
}

