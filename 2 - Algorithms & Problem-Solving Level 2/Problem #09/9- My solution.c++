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

int CheckDigitFrequency(int Number, short CheckDigit)
{
	int Remainder = 0, FreqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		if (CheckDigit == Remainder)
		{
			FreqCount++;
		}
	}

	return FreqCount;
}

void PrintDigitFrequency(int Number, short CheckDigit)
{
	cout << "\n" << "Digit " << CheckDigit << " Frequency is "
	<< CheckDigitFrequency(Number, CheckDigit) << " Time(s)." << endl;

}

int main()
{
	int Number = ReadPositiveNumber("Please enter main Number?");
	short CheckDigit = 0;

	PrintDigitFrequency(Number, 1);
	PrintDigitFrequency(Number, 2);
	PrintDigitFrequency(Number, 3);

	return 0;
}
