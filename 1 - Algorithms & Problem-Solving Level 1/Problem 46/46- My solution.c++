#include <iostream>
#include <string>
using namespace std;

void PrintLettersFromA_Z()
{
    for (int counter = 65; counter <= 90; counter++)
    {
        cout << char (counter) << endl; 
    }
}

int main()
{
    PrintLettersFromA_Z();

    return 0;
}

