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

int SumDigits()
{
	int Number = ReadPositiveNumber("Please enter a Positive Number ?");

	int Remainder = 0;
	int sum = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		sum += Remainder;
		Number = Number / 10;

	}
	return sum;
}

void PrintSumOfDigits()
{
	cout << "\nSum Of Digits = " << SumDigits() << endl;
}

int main()
{
	PrintSumOfDigits();

	return 0;
}

