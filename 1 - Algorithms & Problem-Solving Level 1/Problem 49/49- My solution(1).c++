#include <iostream>
#include <string>
using namespace std;

string ReadATMPIN()
{
	string Password;
	cout << "Please enter ATM PIN Code ?" << endl;
	cin >> Password;

	return Password;
}

void LogIn()
{
	string PinCode;

	do
	{
		PinCode = ReadATMPIN();

		if (PinCode == "1234")
		{
			cout << "\nYour Balance is = " << 7500 << endl;
			system("color 2F");
		}
		else
		{
			cout << "Wrong PIN" << endl;
			system("color 4F");

		}

	} while (PinCode != "1234");

}

int main()
{
	LogIn();

	return 0;
}

