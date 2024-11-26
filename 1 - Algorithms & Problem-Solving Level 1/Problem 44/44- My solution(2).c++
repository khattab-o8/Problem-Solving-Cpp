#include <iostream>
#include <string>
using namespace std;

enum enWeekDays { Sun = 1, Mon = 2, Tues = 3, Wed = 4, Thur = 5, Fri = 6, Sat = 7 , NotAweekDay = 8 };

int ReadDay()
{
    int day = 0, counter = 0;

    cout << "Please enter day Number ? " << endl;
    cin >> day;

    while (day <= 0)
    {
        cout << "Wrong Day!!, Plz enter day again ? " << endl;
        cin >> day;
    }

    return day;
}

enWeekDays ChooseDay(int day)
{
    if (day == 1)
        return enWeekDays::Sun;
    else if (day == 2)
        return enWeekDays::Mon;
    else if (day == 3)
        return enWeekDays::Tues;
    else if (day == 4)
        return enWeekDays::Wed;
    else if (day == 5)
        return enWeekDays::Thur;
    else if (day == 6)
        return enWeekDays::Fri;
    else if (day == 7)
        return enWeekDays::Sat;
    else
        return enWeekDays::NotAweekDay;
}

void PrintDay(enWeekDays WeekDays)
{
    cout << "\n" << "It's ";

    switch (WeekDays)
    {
    case enWeekDays::Sun:
        cout << "Sunday";
        break;

    case enWeekDays::Mon:
        cout << "Monday";
        break;

    case enWeekDays::Tues:
        cout << "Tuesday";
        break;

    case enWeekDays::Wed:
        cout << "Wednesday";
        break;

    case enWeekDays::Thur:
        cout << "Thursday";
        break;

    case enWeekDays::Fri:
        cout << "Friday";
        break;

    case enWeekDays::Sat:
        cout << "Saturday";
        break;

    default:
        cout << "Not aweek day";
        break;
    }
}


int main()
{
    PrintDay(ChooseDay(ReadDay()));
    cout << "\n\n";


    return 0;
}