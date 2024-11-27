#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void PrintAllLettersFromA_To_Z()
{
	for (int i = 65; i <= 90; i++)
	{
		cout << "Letter " << char(i) << ":" << endl;

		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << " " << char(i) << " " << char(j) << endl;
		}
		cout << endl;
	}
}


int main()
{
	system("color 4f");

	PrintAllLettersFromA_To_Z();

	system("pause>0");
}