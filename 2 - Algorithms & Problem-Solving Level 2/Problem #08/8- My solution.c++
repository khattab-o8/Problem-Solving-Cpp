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

int FrequencyNumber(int Number, int Digit)
{
	int Remainder = 0;
	int counter = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		if (Remainder == Digit)
		{
			counter = counter + 1;
		}
		
		
	}
	return counter;
}

int main()
{
	int Number = readPositiveNumber("Please enter a positive Number ?");
	int Digit = readPositiveNumber("Please enter a positive digit ?");

	cout << "\n" << "Digit " << Digit << " Frequency is "
	<< FrequencyNumber(Number, Digit) << " Time(s). " << endl;

	return 0;
}
