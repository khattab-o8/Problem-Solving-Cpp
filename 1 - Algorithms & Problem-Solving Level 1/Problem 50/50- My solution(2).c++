#include <iostream>
#include <string>
using namespace std;

string ReadPinCode()
{
	string PinCode;
	cout << "Please enter Pin Code ?" << endl;
	cin >> PinCode;

	return PinCode;
}

void PrintBalance()
{
	string PinCode;

	for (int counter = 1; counter <= 3; counter++)
	{
		PinCode = ReadPinCode();

		if (PinCode == "1234")
		{
			cout << "\nYour Balance = " << 7500 << endl;
			system("color 2F");
			break;
		}
		else
		{
			cout << "\"Wong PIN\" " << endl << endl;
			system("color 4F");

			if (counter == 3)
			{
				cout << "\n\"Card is locked\"!!" << endl;

			}
		}
	}
}

int main()
{
	PrintBalance();

	return 0;
}

