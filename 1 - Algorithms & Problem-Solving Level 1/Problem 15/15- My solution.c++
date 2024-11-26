#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(int& a, int& b)
{
    cout << "Please enter (a)?\n";
    cin >> a;

    cout << "Please enter (b)?\n";
    cin >> b;
}

int CalculateArea(int a, int b)
{
    int Area;
    Area = a * b;
    return Area;
}

void PrintArea(int Area)
{
    cout << "\nRectangle Area = " << Area << endl;
}


int main()
{
    int a, b;

    ReadNumbers(a, b);
    PrintArea(CalculateArea(a, b));

    return 0;
}

