#include <iostream>
#include <string>
using namespace std;

int ReadATMPinCode()
{
	int Pin = 0;
	cout << "Please enter ATM Pin ? " << endl;
	cin >> Pin;

	return Pin;
}

bool Login()
{
	int Password = 0, counter = 3;
	do
	{
		Password = ReadATMPinCode();

		if (Password == 1234)
		{
			return 1;
		}
		else
		{
			system("color 4F");

			counter--;
			cout << "\n" << "\"Wrong pin!!\" You have " << counter << " try(ies) " << endl << endl;
			if (counter == 0)
			{
				cout << "\n" << "\"Card is Locked!!\", Call your Customer service of your bank.\n\n";
				break;
			}
		}
	} while (Password != 1234);


	return 0;
}


int main()
{
	if (Login())
	{
		system("color 2F");
		cout << "\n" << "Your Balance = 7500 $ " << "\n";
	}

	return 0;
}
