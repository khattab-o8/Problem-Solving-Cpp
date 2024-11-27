#include <iostream>
#include <string>
using namespace std;

string ReadCapitalLetter()
{
	string CapitalLetter;

	cout << "Please enter 3 Capital Letters ?" << endl;
	cin >> CapitalLetter;

	return CapitalLetter;
}

void PrintAllWordsFromAAA_ZZZ(string CapitalLetter)
{
	string word = "";
	int counter = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << "Trial " << "[" << counter++ << "]" << " : " << word << endl;

				if (word == CapitalLetter)
				{
					cout << "\n______________________\n";
					cout << "Password is : " << word << endl;
					cout << "Found after " << counter - 1 << " Trial(s) " << endl;
					break;
				}

				word = "";

			}

		}
	}

}

int main()
{
	PrintAllWordsFromAAA_ZZZ(ReadCapitalLetter());

	return 0;
}