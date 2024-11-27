#include <iostream>
#include <cmath>
using namespace std;

void ReadNumber(int& Number)
{
	cout << "\nPlease enter a number?\n";
	cin >> Number;
}

int MyabsFunction(int Number)
{
	if (Number > 0)
		return Number;
	else
	return Number - (Number) - (Number);
}

int CPPFunction(int Number)
{
	return abs(Number);
}

int main()
{
	int Number = 0;

	ReadNumber(Number);

	cout << "\nMy abs Result : ";
	cout << MyabsFunction(Number) << endl;

	cout << "\nC++ abs Result : ";
	cout << CPPFunction(Number) << endl;

	return 0;
}