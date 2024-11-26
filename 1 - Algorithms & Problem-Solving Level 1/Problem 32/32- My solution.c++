#include <iostream>
#include <string>
using namespace std;

struct STRNumber_Power
{
    int Number;
    int M;  // M refers to power of number.
};

STRNumber_Power ReadNumbers()
{
    STRNumber_Power info;

    cout << "Please enter a Number ? " << endl;
    cin >> info.Number;

    cout << "Please enter a Power (M) ? " << endl;
    cin >> info.M;

    return info;
}

int CalculatePowerOfNumber(STRNumber_Power info)
{
    int Result = pow(info.Number, info.M);

    return Result;
}

void PrintResult(int Result, STRNumber_Power info)
{
    cout << info.Number << " ^ " << info.M << " = " << Result << endl;
}

int main()
{
    STRNumber_Power info = ReadNumbers();
    PrintResult(CalculatePowerOfNumber(info), info);

    return 0;
}

