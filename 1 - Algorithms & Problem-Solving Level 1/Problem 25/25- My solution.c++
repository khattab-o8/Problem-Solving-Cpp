#include <iostream>
#include <string>
using namespace std;

short ReadAge()
{
	short Age = 0;

	cout << "Please enter Your Age ?\n";
	cin >> Age;

	return Age;
}

bool ValidateNumberInRange(short Number, short From, short To)
{
	return (Number >= From && Number <= To);
}

void PrintResult(short Age)
{
	if (ValidateNumberInRange(Age, 18, 45))
	{
		cout << "\nValid Age\n";
	}
	else
	{
		do
		{
			cout << "\nInvalid Age!! Plz enter a valid Age ? \n";
			cin >> Age;

		} while (Age < 18 || Age > 45);

		cout << "\nThe Age you entered is : " << Age << " \"Valid\" \n";
	}

}


int main()
{
	PrintResult(ReadAge());

	return 0;
}