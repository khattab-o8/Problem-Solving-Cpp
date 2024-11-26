#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int Number;

    cout << "Please enter a Number?" << endl;
    cin >> Number;

    return Number;
}

void PrintRangefromNTo1_UsingForLoop(int N)
{
    cout << "Printed Range Using For Statement :- " << endl;

    for (int counter = N; counter >=1; counter--)
    {
        cout << counter << endl;
    }
}

void PrintRangefromNTo1_UsingWhileLoop(int N)
{
    cout << "Printed Range Using While Statement :- " << endl;

    int counter = N + 1;
    while (counter > 1)
    {
        counter--;
        cout << counter << endl;
    }
}

void PrintRangefromNTo1_UsingDO_WhileLoop(int N)
{
    cout << "Printed Range Using Do..While Statement :- " << endl;

    int counter = N + 1;
    do
    {
        counter--;
        cout << counter << endl;

    } while ( counter > 1 );
}

int main()
{
    int N = ReadNumber();

    PrintRangefromNTo1_UsingForLoop(N);
    PrintRangefromNTo1_UsingWhileLoop(N);
    PrintRangefromNTo1_UsingDO_WhileLoop(N);

    return 0;
}

