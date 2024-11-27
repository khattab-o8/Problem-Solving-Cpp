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

void PutNumbersInOrder(int Number, short Digit)
{
	int Remainder = 0;
	while (Number > 0 )
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Remainder ==  Digit)
		{
			cout << Digit << endl;
		}
	}
}

void PrintNumbersInOrder_FromLeft_ToRight(int Number)
{
	cout << "OutPut : " << "\n";

	for (int i = 0; i < 10; i++)
	{
		PutNumbersInOrder(Number, i);
	}

}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive Number ?");
	PrintNumbersInOrder_FromLeft_ToRight(Number);

	return 0;
}
