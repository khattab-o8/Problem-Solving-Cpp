#include <iostream>
#include <string>
using namespace std;

void FibonacciSeries()
{
	short Prev2 = 0, Prev1 = 1;
	short sum = 0;

	cout << 1 << "  ";

	for (short i = 1; i < 10; i++)
	{
		sum = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = sum;

		cout << sum << "  ";
	}
}

int main()
{
	cout << "\nFibonacci Series of 10.\n\n";

	FibonacciSeries();

	system("pause > 0");
	return 0;
}


