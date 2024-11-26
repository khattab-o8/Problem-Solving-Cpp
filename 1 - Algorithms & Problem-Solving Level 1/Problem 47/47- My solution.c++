#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Massage)
{
    int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

struct strLoan_Payment
{
	int LoanAmount, MonthlyPayment;
};

strLoan_Payment ReadAmount()
{
	strLoan_Payment Input;

	Input.LoanAmount = ReadPositiveNumber("Please enter Loan Amount ?");
	Input.MonthlyPayment = ReadPositiveNumber("Please enter Monthly Payment ?");

	return Input;
}

int CalculateMonthsToSettle_Loan(strLoan_Payment Input)
{
	int M = 0;
	M = (float)Input.LoanAmount / Input.MonthlyPayment;

	return M;
}


int main()
{
	
	cout << "\nMonths Needed to settle the loan = " << CalculateMonthsToSettle_Loan(ReadAmount()) << " months " << endl;

    return 0;
}

