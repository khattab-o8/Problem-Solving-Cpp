#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string NumberOfTabs(short Number)
{
	string Tabs;
	for (short i = 1; i <= Number; i++)
	{
		Tabs = Tabs + "\t";
	}

	return Tabs;
}

string NumberOfUnderScore(short Number)
{
	string Scoor;
	for (short s = 1; s <= Number; s++)
	{
		Scoor = Scoor + "___";
	}

	return Scoor;
}

string SpaceNumbering(short Number)
{
	if (Number < 10)
	{
		return "   |";
	}
	else
	{
		return "  |";
	}
}

void TableHeader()
{

	cout << "\n\n" << NumberOfTabs(3) << " Multiplication Table From 1 to 10\n" << endl;

	for (short i = 1; i <= 10; i++)
	{
		cout << NumberOfTabs(1) << i;
	}

	cout << "\n" << NumberOfUnderScore(28) << "\n";
}

void MultiplicationTable()
{
	TableHeader();

	for (short i = 1; i <= 10; i++)
	{
		cout << i << SpaceNumbering(i);

		for (short j = 1; j <= 10; j++)
		{
			cout << "\t" << i * j;
		}
		cout << endl;
	}

	cout << "\n\n";
}


int main()
{
	system("color 5F");

	MultiplicationTable();

	system("pause > 0");
}