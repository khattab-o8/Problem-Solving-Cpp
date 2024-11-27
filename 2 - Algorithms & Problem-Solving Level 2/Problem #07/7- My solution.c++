#include <iostream>
#include <string>
using namespace std;

int readPositiveNumber(string Massage)
{
	int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void PrintReversedDigits(int Number)
{
	cout << "\nReverse is :" << endl;

	int Remainder = 0;
	string Collector;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Collector = to_string(Remainder);
		cout << Collector;
	}
	cout << "\n";
}

int main()
{
	PrintReversedDigits(readPositiveNumber("Please enter a positive Number ?"));

	return 0;
}

