#include <iostream>
#include <string>
using namespace std;

float Readnumber(string Massage)
{
    float number;
    cout << Massage << endl;
    cin >> number;

    return number;
}

float CalculateBillValue(float BillValue)
{
    float Bill = 0;
    Bill = BillValue + (BillValue * .10);

    return Bill;
}

float CalculateSalesTax(float Bill)
{
    float SalesTax = 0;
    SalesTax = Bill * .16;

    return SalesTax;
}

float CalculateBillAfterTax(float Bill, float SalesTax)
{
    return (Bill + SalesTax);
}

int main()
{
    float BillValue = Readnumber("Please enter Bill Value ?");
    float Bill = CalculateBillValue(BillValue);
    float SalesTax = CalculateSalesTax(Bill);

    cout << "\n" << "Total Bill Value before Tax = " << CalculateBillValue(BillValue) << endl;
    cout << "Sales Tax = " << CalculateSalesTax << endl;
    cout << "********************************\n";
    cout << "Total Bill After Tax = " << CalculateBillAfterTax(Bill, SalesTax) << endl;

    return 0;
}

