#include <iostream>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "\nPlease enter a Number ? \n";
	cin >> Number;

	return Number;
}

float GetFractionPart(float Number)
{
	return Number - int(Number);
}

int MyFloor(float Number)
{
	int IntegerPart = 0;
	IntegerPart = int(Number);

	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) < 10)
	{
		if (Number > 0)
			return IntegerPart;
		else
			return --IntegerPart;
	}
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Floor Result : " << MyFloor(Number) << endl;
	cout << "C++ Floor Result : " << floor(Number) << endl;


	return 0;
}