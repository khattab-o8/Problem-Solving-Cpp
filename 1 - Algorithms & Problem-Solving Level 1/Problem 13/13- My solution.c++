#include <iostream>
#include <string>
using namespace std;

void ReadABC(int& A, int& B, int& C)
{
    cout << "Please enter A ?\n";
    cin >> A;

    cout << "Please enter B ?\n";
    cin >> B;

    cout << "Please enter C ?\n";
    cin >> C;
}


int Maxof3NumbersABC(int A, int B, int C)
{
    if (A > B && A > C)
        return A;
    else if (C > A && C > B)
        return C;
    else
        return B;
}

void PrintMaximumNumber(int Max )
{
    cout << "The Maximum Number is : " << Max << endl;

}


int main()
{
    int A, B,C;

    ReadABC(A, B, C);
    PrintMaximumNumber(Maxof3NumbersABC(A, B, C));

    return 0;
}

