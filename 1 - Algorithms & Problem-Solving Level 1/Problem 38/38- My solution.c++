#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime {Prime = 1, NotPrime = 2};

int ReadPositiveNumber(string Massage)
{
	int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0 );

	return Number;
}

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}
	}

	return enPrimeNotPrime::Prime;
}

string PrintPrime_NotPrime(int Number)
{
	switch (CheckPrime(Number))
	{
	case enPrimeNotPrime::Prime:
		return "Prime";

	case enPrimeNotPrime::NotPrime:
		return "Not Prime";
	
	}
}

int main()
{

	cout << "You Number is : " <<
	PrintPrime_NotPrime
	(ReadPositiveNumber("Please enter a Number ?")) << endl;


	return 0;
}