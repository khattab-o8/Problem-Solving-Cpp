#include <iostream>
#include <string>
using namespace std;

enum enPerfectNotPerfect { Perfect = 1, NotPerfect = 2 };

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

int CheckNumber(int Number)
{
	int S = Number - 1;
	int sum = 0;
	for (int counter = 1; counter <= S; counter ++)
	{
		if (Number % counter == 0 )
		{
			sum = sum + counter;
		}
	}
	return sum;
}

enPerfectNotPerfect CheckPerfect(int sum, int Number)
{
	if (sum == Number)
		return enPerfectNotPerfect::Perfect;
	else
		return enPerfectNotPerfect::NotPerfect;
}

void PrintPerfectNumber(int sum,int Number)
{
	switch (CheckPerfect(sum, Number))
	{
	case enPerfectNotPerfect::Perfect:
		cout << "\n" << Number << "  is perfect Number\n";
		break;

	case enPerfectNotPerfect::NotPerfect:
		cout << "\n" << Number << "  is not perfect Number\n";
		break;
	}

}

int main()
{
	int Number = ReadPositiveNumber("Please enter a positive Number ?");
	int sum = CheckNumber(Number);
	PrintPerfectNumber(sum, Number);

	return 0;
}

