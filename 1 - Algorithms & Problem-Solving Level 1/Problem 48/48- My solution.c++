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

float MonthlyInstallmentAmount(float LoanAmount, float TotalMonths)
{
	return (float)LoanAmount / TotalMonths;
}

int main()
{
	float LoanAmount = ReadPositiveNumber("Please enter Loan Amount ?");
	float TotalMonths = ReadPositiveNumber("Please enter Number Of Months to settle The Loan ?");

	cout << "\nMonthly Installment Amount = " << MonthlyInstallmentAmount(LoanAmount, TotalMonths) << " $ " << endl;

    return 0;
}

