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

void CheckPINCode(int Password)
{
	if (Password == 1234)
	{
		cout << "\nYour Balance = 7500" << endl;
	}
	else
		do
		{
			cout << "Wong PIN" << endl;
			cin >> Password;
			if (Password == 1234)
			{
				cout << "\nYour Balance = 7500" << endl;
				break;
			}

		} while (Password != 1234);
}

int main()
{
	int Password = ReadPositiveNumber("Please enter ATM PIN Code ?");
	CheckPINCode(Password);

	return 0;
}

