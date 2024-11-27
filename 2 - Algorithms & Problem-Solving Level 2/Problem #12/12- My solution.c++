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

void PrintInvertedPattern(int Number)
{
	cout << "\n";

	for (int i = Number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
	
}

int main()
{

	PrintInvertedPattern(ReadPositiveNumber("Please enter a Positive Number ? "));

	return 0;
}
