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

void PrintNumberInReveredOrder(int Number)
{
	cout << "\n\n" << "Output : " << endl;

	int Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		cout << Remainder << endl;
	}
}

int main()
{
	PrintNumberInReveredOrder(ReadPositiveNumber("Please enter a positive Number ?"));

	return 0;
}