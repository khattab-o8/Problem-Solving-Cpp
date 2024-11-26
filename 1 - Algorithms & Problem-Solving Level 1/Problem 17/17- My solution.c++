#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(float& A, float& H)
{
    cout << "Please enter triangle base A ?\n";
    cin >> A;

    cout << "Please enter triangle high H ?\n";
    cin >> H;
}

float TriangleAreaByBaseAndHigh(float A, float H)
{
    float Area = 0.5 * A * H;
    return Area;
}

void PrintResult(float Area)
{
    cout << "\nTriangle Area = " << Area << endl;


}

int main()
{
    float A, H;
    ReadNumbers(A,H);
    PrintResult(TriangleAreaByBaseAndHigh(A,H));
    return 0;
}

