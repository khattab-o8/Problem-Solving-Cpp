#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
	string Password;
	cout << "Please Enter Your Password ? " << endl;
	cin >> Password;

	return Password;
}

bool GuessPassword(string Password)
{
	string word = "";
	int counter = 0;

	for (short i = 65; i <= 90; i++)
	{
		for (short j = 65; j <= 90; j++)
		{
			for (short k = 65; k <= 90; k++)
			{
				counter++;

				word = word + char(i);
				word = word + char(j);
				word = word + char(k);


				cout << "Trial [" << counter << "]: " << word << endl;

				if (word == Password)
				{
					system("color 2f");
					cout << "\n\n" << "Password is : " << word << endl;
					cout << "\n" << "Found after " << counter << " Trial(s)." << endl;
					return true;
				}
				word = "";
			}
		}
	}

	return false;
}


int main()
{

	GuessPassword(ReadPassword());

	system("pause > 0");
}