#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(int& Number, int& M)
{
    cout << "Please enter a Number ? " << endl;
    cin >> Number;

    cout << "Please enter a power (M) ? " << endl;
    cin >> M;
}

void PowerOfNumber(int Number, int M)
{
  
    int R = pow(Number, M);
    cout << "\n" << Number << " ^ " << M << " = " << R << endl;

}

int main()
{
    int Number = 0;
    int M = 0;

    ReadNumbers(Number,M);
    PowerOfNumber(Number, M);

    return 0;
}

