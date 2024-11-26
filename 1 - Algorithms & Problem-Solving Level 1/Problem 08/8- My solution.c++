#include <iostream>
#include <string>
using namespace std;

int ReadMark()
{
    int mark;
    cout << "Please enter a mark ?\n";
    cin >> mark;

    return mark;
}

string CheckMark(int mark)
{
    if (mark >= 50)
    {
        return "\n\"Pass\"";
    }
    else
    {
        return "\n\"Fail\"";
    }

}

void PrintResult(int mark)
{
    cout << CheckMark(mark) << endl;

}


int main()
{
    PrintResult(ReadMark());

    return 0;
}
