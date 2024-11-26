#include <iostream>
#include <string>
using namespace std;

void ATMPINCode()
{
	int PIN = 0;
	do
	{
		cout << "Please enter ATM PIN Code ?" << endl;
		cin >> PIN;
		if (PIN == 1234)
		{

			cout << "\nYour Balance = 7500" << endl;
		}

	} while (PIN != 1234);

}


int main()
{
	ATMPINCode();

	return 0;
}

