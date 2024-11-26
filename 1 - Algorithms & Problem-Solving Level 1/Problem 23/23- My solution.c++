#include <iostream>
#include <string>
using namespace std;

void ReadTriangleData(float& A, float& B, float& C)
{
    cout << "Please enter First Triangle Side A ?" << endl;
    cin >> A;

    cout << "Please enter Second Triangle Side C ?" << endl;
    cin >> C;

    cout << "Please enter Triangle base B ?" << endl;
    cin >> B;
}

float CalculateCircleAreaDescribedAroundArbitraryTriangle(float A, float B, float C)
{
    const float PI = 3.141592653589793238;
    float P = (A + B + C) / 2;
    float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
    float S = pow(T, 2);
    float Area = PI * S;

    return Area;
}

void PrintResult(float Area)
{
    cout << "\nCircle area described around an arbitrary triangle = " << Area << endl;
}

int main()
{
    float A, B, C;
    ReadTriangleData(A,B,C);
    PrintResult(CalculateCircleAreaDescribedAroundArbitraryTriangle(A,B,C));

    return 0;
}

