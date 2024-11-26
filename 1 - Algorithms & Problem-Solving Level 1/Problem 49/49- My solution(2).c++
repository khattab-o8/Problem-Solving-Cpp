#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber()
{
	int Number = 0;
	do
	{
		cout << "Please enter your Pin Code ? " << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

string CheckPinCode(int PinCode)
{
	if (PinCode == 1234)
		return "Your Balance is : 7500";
	else
	{
		while (PinCode != 1234)
		{
			cout << "Wrong PIN !!, Plz enter Pin again ? " << endl;
			cin >> PinCode;
		}
		return "Your Balance is : 7500";
	}
}


int main()
{
	cout << CheckPinCode(ReadPositiveNumber()) << "\n";


	return 0;
}
