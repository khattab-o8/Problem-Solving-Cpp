#include <iostream>
#include <cmath>
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

int MyCeil(float Number)
{
	int IntegerPart = 0;
	IntegerPart = int(Number);
	float FractionPart = GetFractionPart(Number);

	if (abs(FractionPart) == 0)
	{
		return int(Number);
	}
	else if (abs(FractionPart) > 0)
	{
		if (Number > 0)
			return int(Number) + 1;
		else
			return int(Number);
	}
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Ceil Result : " << MyCeil(Number) << endl;
	cout << "C++ Ceil Result : " << ceil(Number) << endl;


	return 0;
}