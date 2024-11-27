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

	} while ( Number <= 0 );

	return Number;
}

bool IsPerfectNumber(int Number)
{
	int sum = 0;
	for (int i = 1; i < Number; i++)
	{
		if (Number % i == 0 )
		{
			sum += i;
		}

	}

	return Number == sum;
}

void PrintPerfectNumbersFrom1ToN(int Number)
{
	cout << "\nAll Perfect Numbers From 1 to " << Number << " are : " << endl;

	for (int counter = 1; counter <= Number; counter++)
	{
		if (IsPerfectNumber(counter))
		{
			cout << counter << endl;
		}
	}
}

int main()
{
	PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive Number ?"));

	return 0;
}

