#include <iostream>
#include <string>
using namespace std;

float ReadSquareSide()
{
    float A;
    cout << "Please enter square Side A ?\n";
    cin >> A;

    return A;
}

float CircleAreaInscribedInAsquare(float A)
{
    const float PI = 3.141592653589793238;
    float Area = (PI * pow(A, 2)) / 4;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle area inscribed in a square = " << Area << endl;

}

int main()
{
    PrintResult(CircleAreaInscribedInAsquare(ReadSquareSide()));

    return 0;
}

