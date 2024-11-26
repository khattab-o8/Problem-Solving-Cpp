#include <iostream>
#include <string>
using namespace std;

void ReadNumber(float& R)
{
    cout << "Please enter Circle Radius R ? \n";
    cin >> R;
}

float CalculataCircleArea(float R)
{
    float Area = 3.14159 * pow(R, 2);
    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    float R;
    ReadNumber(R);
    PrintResult(CalculataCircleArea(R));

    return 0;
}

