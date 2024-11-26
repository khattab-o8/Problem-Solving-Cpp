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

struct strLoan_Months
{
	float LoanAmount, TotalMonths;

};

strLoan_Months ReadLoanAmount_NOfMonths()
{
	strLoan_Months Input;

	Input.LoanAmount = ReadPositiveNumber("Please enter Loan Amount ?");
	Input.TotalMonths = ReadPositiveNumber("Please enter Number Of Months to settle The Loan ?");

	return Input;
}

float MonthlyInstallmentAmount(strLoan_Months Input)
{
	return (float)Input.LoanAmount / Input.TotalMonths;
}


int main()
{
	cout << "\nMonthly Installment Amount = " << MonthlyInstallmentAmount(ReadLoanAmount_NOfMonths()) << " $ " << endl;

    return 0;
}

