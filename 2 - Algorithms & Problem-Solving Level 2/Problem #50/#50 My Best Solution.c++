#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "\nPlease enter a Number ?  ";
	cin >> Number;

	return Number;
}

float MySqrt(float Number)
{
	// Assume that Number = 25.

	for (int i = Number; i >= 1; i--)

		if ((i * i) <= Number)
			return i;
}

int main()
{
	float Number = ReadNumber();

	cout << "\nMy Sqrt Result : " << MySqrt(Number);
	cout << "\nC++ Sqrt Result : " << sqrt(Number) << "\n\n";


	return 0;
}