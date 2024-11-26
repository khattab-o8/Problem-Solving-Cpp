#include <iostream>
#include <string>
using namespace std;

struct strMyNumbers
{
    int Num1, Num2, Num3;

};

strMyNumbers ReadNumbers()
{
    strMyNumbers input;

    cout << "Please enter Number1 ? \n";
    cin >> input.Num1;
    cout << "Please enter Number2 ? \n";
    cin >> input.Num2;
    cout << "Please enter Number3 ? \n";
    cin >> input.Num3;

    return input;
}

int SumNumbers(strMyNumbers input)
{
    int sum;
    sum = input.Num1 + input.Num2 + input.Num3;

    return sum;
}

void PrintNumbers(strMyNumbers input)
{
    cout << "\nThe Sum Of entered Numbers is : " << SumNumbers(input) << endl;
}


int main()
{
    PrintNumbers(ReadNumbers());

    return 0;
}

