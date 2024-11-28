#include <iostream>
#include <string>
using namespace std;

void FibonacciSeries(short Number, short Prev2, short Prev1)
{
	short sum;
	Number++;
	if (Number < 10)
	{
		sum = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = sum;

		cout << sum << "  ";
		FibonacciSeries(Number, Prev2, Prev1);
	}
}

int main()
{
	cout << "\nFibonacci Series of 10.\n\n";

	cout << 1 << "  ";;
	FibonacciSeries(0,0,1);

	system("pause > 0");
	return 0;
}


