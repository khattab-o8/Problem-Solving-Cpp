#include <iostream>
#include <string>
using namespace std;

float ReadData(string Massage)
{
    float Number;
    cout << Massage << endl;
    cin >> Number;

    return Number;
}

float CalculateRemainder(float TotalBill, float Cashpaid)
{
    float Remainder = 0;
    Remainder = Cashpaid - TotalBill;

    return Remainder;
}

void PrintRemainder(float Remainder)
{
    cout << "\n" << "The Remainder = " << Remainder << endl;
}

int main()
{
    float TotalBill = ReadData("Please enter TotalBill ?");
    float Cashpaid = ReadData("Please enter CashPaid ?");

    PrintRemainder(CalculateRemainder(TotalBill, Cashpaid));

    return 0;
}

