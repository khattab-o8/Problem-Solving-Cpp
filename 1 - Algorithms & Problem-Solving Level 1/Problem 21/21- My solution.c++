#include <iostream>
#include <string>
using namespace std;

float ReadPointOnCircleCircumference()
{
    float L;
    cout << "Please enter Point Value on circle Circumference L ?" << endl;
    cin >> L;

    return L;
}

float CalculateCircleAreaAlongTheCircumference(float L)
{
    const float PI = 3.141592653589793238;

    float Area = (pow(L, 2)) / (4 * PI);

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle area along the circumference = " << Area << endl;
}

int main()
{
    PrintResult(CalculateCircleAreaAlongTheCircumference(ReadPointOnCircleCircumference()));

    return 0;
}

