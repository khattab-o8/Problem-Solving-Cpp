#include <iostream>
using namespace std;

void ReadMarks(int& Mark1, int& Mark2, int& Mark3)
{
    cout << "Please enter Mark1 ? \n";
    cin >> Mark1;

    cout << "Please enter Mark2 ? \n";
    cin >> Mark2;

    cout << "Please enter Mark3 ? \n";
    cin >> Mark3;
}


int SumofMarks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;
}


float AverageofMarks(int Mark1, int Mark2, int Mark3)
{
    return (float) SumofMarks(Mark1, Mark2, Mark3) / 3;
}


void PrintAverage(int& Mark1, int& Mark2, int& Mark3)
{
    cout << "\nThe Average is :" << AverageofMarks(Mark1, Mark2, Mark3) << endl;

    float output = AverageofMarks(Mark1, Mark2, Mark3);
    if (output >= 50)
        cout << "\"Passed\"" << endl;
    else
        cout << "\"Failed\"" << endl;
}


int main()
{
    int Mark1, Mark2, Mark3;
    ReadMarks(Mark1, Mark2, Mark3);
    PrintAverage(Mark1, Mark2, Mark3);


    return 0;
}

