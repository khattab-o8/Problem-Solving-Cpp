#include <iostream>
#include <string>
using namespace std;

float ReadPositiveNumber(string Massage)
{
	float Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

float AddServiceFeeToBillValue(float BillValue)
{
	float TotalBill = BillValue + (BillValue * .10);
	return TotalBill;
}

float TotalBillAfterAddingSalesTax(float TotalBill)
{
	return TotalBill + (TotalBill * .16);
}

void PrintResult(float Bill)
{
	cout << "\n*******************************************" << "\n";
	cout << "Bill Value = " << Bill << endl;
	cout << "Service Fee =  10 % " << endl;
	cout << "Bill Value after adding Service Fee =  "
		<< AddServiceFeeToBillValue(Bill) << endl;

	cout << "Sales Tax = 16 % " << endl;
	cout << "Total Bill after adding sales tax = "
		<< TotalBillAfterAddingSalesTax
		(AddServiceFeeToBillValue(Bill)) << endl;
	cout << "*******************************************" << "\n";
}

int main()
{
	float Bill = ReadPositiveNumber("Please enter Bill Value ?");
	PrintResult(Bill);


	return 0;
}