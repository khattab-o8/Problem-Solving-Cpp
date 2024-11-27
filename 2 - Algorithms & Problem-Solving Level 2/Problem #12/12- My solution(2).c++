#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Massage)
{
	int N = 0;
	do
	{
		cout << Massage << endl;
		cin >> N;

	} while (N <= 0);

	return N;
}

void PrintLoops(int N)
{
	cout << "\n";

	for (int i = N; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}
		cout << endl;
	}
	
}

int main()
{

	PrintLoops(ReadPositiveNumber("Please enter a Positive Number ? "));

	return 0;
}
