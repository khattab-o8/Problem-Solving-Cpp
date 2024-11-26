#include <iostream>
#include <string>
using namespace std;

struct STRNumbers
{
    int Num1, Num2;

};

STRNumbers ReadNumbers()
{
    STRNumbers input;
    cout << "Please enter Number 1 ?\n";
    cin >> input.Num1;

    cout << "Please enter Number 2 ?\n";
    cin >> input.Num2;

    return input;
}

void MaxNumber(STRNumbers input)
{
    if (input.Num1 > input.Num2)
        cout << "\nThe Maximum Number is : " << input.Num1 << endl;
    else
        cout << "\nThe Maximum Number is : " << input.Num2 << endl;
}



int main()
{
    MaxNumber(ReadNumbers());
    return 0;
}

