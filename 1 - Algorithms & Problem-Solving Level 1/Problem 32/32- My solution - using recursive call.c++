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

int CalculatePowerOfNumber(int Num, int P)
{
	if (P == 0)
	{
		return 1;
	}
	else
	{
		return Num * CalculatePowerOfNumber(Num, P - 1);
	}
}
	

int main()
{
	int Number = ReadPositiveNumber("Please enter a Positive Number ?");
	int Power = ReadPositiveNumber("Please enter The Power (P) ?");

	cout << "\nNumber ^ P = " << CalculatePowerOfNumber(Number, Power) << endl;
		
	return 0;
}