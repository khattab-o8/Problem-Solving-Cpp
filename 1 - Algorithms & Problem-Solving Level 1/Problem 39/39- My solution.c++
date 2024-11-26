#include <iostream>
#include <string>
using namespace std;

void ReadTransaction(float& TotalBill, float& Cashpaid)
{
    cout << "Please enter TotalBill ? " << endl;
    cin >> TotalBill;

    cout << "Please enter CashPaid ? " << endl;
    cin >> Cashpaid;
}

float CalculateRemainder(float TotalBill, float Cashpaid)
{
    float Remainder = 0;
    Remainder = Cashpaid - TotalBill;

    return Remainder;

}


int main()
{
    float TotalBill = 0;
    float Cashpaid = 0;
    ReadTransaction(TotalBill, Cashpaid);
    cout << "\n" << "The Remainder = " << CalculateRemainder(TotalBill, Cashpaid) << endl;

    return 0;
}

