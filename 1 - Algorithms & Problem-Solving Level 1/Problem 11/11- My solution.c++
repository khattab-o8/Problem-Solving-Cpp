#include <iostream>
#include <string>
using namespace std;

enum enPassFail {Pass = 1 , Fail = 2};

struct STRMarks
{
    int mark1, mark2, mark3;

    STRMarks() = default;
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
    float Average;
    Average = (float)((input.mark1 + input.mark2 + input.mark3) / 3);

    return Average;
}

enPassFail CheckAverage(float Average)
{
    enPassFail info;
    if (Average >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

void PrintAverage(float Average)
{

    string output = "\nThe Average of entered Marks is :" + to_string(Average);
    cout << output << endl;

    if (CheckAverage(Average) == enPassFail::Pass)
        cout << "\"You Passsed\"" << endl;
    else
        cout << "\"You Failed\"" << endl;
  
}


int main()
{
    PrintAverage(AverageofMarks(ReadMarks()));

    return 0;
}

