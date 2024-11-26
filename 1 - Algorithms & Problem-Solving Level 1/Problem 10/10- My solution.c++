#include <iostream>
#include <string>
using namespace std;

struct STRMarks
{
    int mark1, mark2, mark3;
};

STRMarks ReadMarks()
{
    STRMarks input;
    cout << "Please enter Mark1 ? \n";
    cin >> input.mark1;

    cout << "Please enter Mark2 ? \n";
    cin >> input.mark2;

    cout << "Please enter Mark3 ? \n";
    cin >> input.mark3;

    return input;
}

float AverageofMarks(STRMarks input)
{
    return (float)((input.mark1 + input.mark2 + input.mark3) / 3);

}

void PrintAverage(STRMarks input)
{
    string output = "\nThe Average of entered Marks is :" + to_string(AverageofMarks(input));

    cout << output << endl;

}


int main()
{
    PrintAverage(ReadMarks());

    return 0;
}

