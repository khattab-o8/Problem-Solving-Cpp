#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckPrime(int Number)
{
	int A = round(Number / 2);

	for (int counter = 2; counter <= A; counter++)
	{
		if (Number % counter == 0 )
		{
			return enPrimeNotPrime::NotPrime;
		}
	}
	return enPrimeNotPrime::Prime;

}

void PrintPrimeNumbers(int Number)
{
	cout << "\nPrime Numbers From 1 To " << Number << " are : " << endl;

	for (int i = 1; i <= Number ; i++)
	{
		if (CheckPrime(i) == enPrimeNotPrime::Prime)
		{
			cout << i << endl;
		}
	}

}


int main()
{
	PrintPrimeNumbers(ReadPositiveNumber("Please enter a positive Number ?"));

    return 0;
}

