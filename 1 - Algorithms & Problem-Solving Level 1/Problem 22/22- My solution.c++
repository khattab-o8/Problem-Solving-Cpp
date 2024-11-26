#include <iostream>
#include <string>
using namespace std;

void ReadTriangleSideAndBase(float& A, float& B)
{
    cout << "Please enter Triangle Side A ?" << endl;
    cin >> A;

    cout << "Please enter Triangle base B ?" << endl;
    cin >> B;
}

float CircleAreaInscribedInAnIsoscelesTriangle(float A, float B)
{
    const float PI = 3.141592653589793238;
    float T = pow(B, 2) / 4;
    float S = (2 * A - B) / (2 * A + B);

    return (PI * T * S);
}

void PrintResult(float Area)
{
    cout << "\nCircle Area Inscribed in an Isosceles Triangle = " << Area << endl;
}

int main()
{
    float A, B;
    ReadTriangleSideAndBase(A,B);
    PrintResult(CircleAreaInscribedInAnIsoscelesTriangle(A,B));

    return 0;
}

