#include <iostream>
#include <string>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t\t\t\"Multiplication Table From 1 to 10\"\n\n";
	cout << "\t";

	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t";

	}

	cout << "\n_____________________________________________________________________________________\n";
}

string ColumSeparator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}

void PrintMultiplyTable()
{
	PrintTableHeader();

	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumSeparator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j << "\t";

		}

		cout << endl;
	}
}

int main()
{
	PrintMultiplyTable();

	return 0;
}

