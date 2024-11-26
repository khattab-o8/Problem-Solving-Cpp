#include <iostream>
#include <string>
using namespace std;

enum enValidInvalid { Valid = 1 , InValid = 2 };

int ValidateNumberInRange(int From, int To)
{
	int Age = 0;
	
	cout << "Please enter Age between " << From << " and " << To << endl;
	cin >> Age;

	return Age;
}

enValidInvalid CheckAge(int Age, int From, int To)
{
	if (Age > From && Age < To)
	{
		return enValidInvalid::Valid;
	}

	return enValidInvalid::InValid;
}

string Result(enValidInvalid Age)
{
	switch (Age)
	{
	case enValidInvalid::Valid:
		return "Valid Age";

	case enValidInvalid::InValid:
		return "InValid Age";
	
	}
}

int main()
{
	int Age = ValidateNumberInRange(18, 45);

	cout << "\n" << Result(CheckAge(Age, 18, 45)) << "\n";

	return 0;
}