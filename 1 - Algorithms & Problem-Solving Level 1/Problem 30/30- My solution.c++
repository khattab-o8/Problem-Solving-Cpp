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

int CalculateFactorialOfN(int Number)
{
	int Factorial = 1;

	for (int i = Number; i >= 1; i--)
	{
		Factorial = Factorial * i;
	}

	return Factorial;
}

int main()
{
	cout << "\nFactorial Of Number = "
		<< CalculateFactorialOfN
		(ReadPositiveNumber("Please enter a Positive Number ?")) << endl;


	return 0;
}