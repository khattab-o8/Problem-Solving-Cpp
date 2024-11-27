#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime {Prime = 1 , NotPrime = 2};

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
	for (short i = 2; i <= M; i++)
	{
		if (Number % i == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}

	return enPrimeNotPrime::Prime;
}

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

void PrintPrimeNumbers(int Number)
{
	cout << "\n" << "Prime Numbers from 1 to " << Number << " are : " << endl;

	for (short i = 1; i <= Number; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}
}

int main()
{
	system("color 4f");

	int Number = ReadPositiveNumber("Please enter a Positive Number ?");
	PrintPrimeNumbers(Number);

	system("pause > 0");
}