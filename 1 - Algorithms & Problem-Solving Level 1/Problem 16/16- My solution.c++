#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void ReadNumbers(float& a, float& d)
{
    cout << "Please enter Rectangle Width [ a ] ?\n";
    cin >> a;

    cout << "Please enter Rectangle Diagonal [ d ] ?\n";
    cin >> d;
}

float CalculateArea(float a, float d)
{
    float Area;
    Area = a * sqrt(pow(d, 2) - pow(a, 2));
    return Area;
}

void PrintArea(float Area)
{
    cout << "\nRectangle Area through diagonal and side Area = " << Area << endl;
}


int main()
{
    float a, d;

    ReadNumbers(a, d);
    PrintArea(CalculateArea(a, d));

    return 0;
}

