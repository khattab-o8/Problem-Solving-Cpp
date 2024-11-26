#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string Massage)
{
    int Number;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number < 0);

	return Number;
}

int NumberOfPower2(int Number)
{
	return pow(Number, 2);
}

int NumberOfPower3(int Number)
{
	return pow(Number, 3);
}

int NumberOfPower4(int Number)
{
	return pow(Number, 4);
}

void PrintResult(int Number)
{
	cout << "\n" << Number << " ^2 = " << NumberOfPower2(Number) << endl;
	cout << Number << " ^3 = " << NumberOfPower3(Number) << endl;
	cout << Number << " ^4 = " << NumberOfPower4(Number) << endl;
}

int main()
{
	PrintResult(ReadNumber("Please enter a positive Number ?"));

    return 0;
}

