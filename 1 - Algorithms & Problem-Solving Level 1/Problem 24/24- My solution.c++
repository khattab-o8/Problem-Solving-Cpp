#include <iostream>
#include <string>
using namespace std;

enum ValidInvalid {Valid =1, Invalid=2};

int ReadAge()
{
    int Age;
    cout << "Please enter your Age?\n";
    cin >> Age;

    return Age;
}

ValidInvalid CheckAge(int Age)
{
    if (Age >= 18 && Age <= 45)
        return ValidInvalid::Valid;
    else
        return ValidInvalid::Invalid;
}

void PrintOutPut(int Age)
{
    if (CheckAge(Age) == ValidInvalid::Valid)
        cout << "\nValid Age" << endl;
    else
        cout << "\nInvalid Age" << endl;
}

int main()
{
    PrintOutPut(ReadAge());

    return 0;
}

