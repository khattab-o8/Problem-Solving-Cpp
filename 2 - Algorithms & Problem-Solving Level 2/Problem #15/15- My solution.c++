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

void PrintLetterPattern(int Number)
{
	cout << "\n";
	int S = 65 + (Number - 1);

	for (int i = 65; i <= S; i++)
	{
		for (int j = 65; j <= i; j++)
		{
			cout << char(i);

		}
		cout << endl;
	}
}

int main()
{
	PrintLetterPattern(ReadPositiveNumber("Please enter a positive Number ?"));

	return 0;
}
