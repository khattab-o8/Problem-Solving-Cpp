Problem #22

#include <iostream>
#include <string>
using namespace std;

void FibonacciSeriesUsingRecursion(int Prev2,int Prev1, int Number)
{
	int FebNumber = Prev1 + Prev2;

	if (Number > 1)
	{
		cout << FebNumber << "   ";
		Prev2 = Prev1;
		Prev1 = FebNumber;

		FibonacciSeriesUsingRecursion(Prev2, Prev1, Number - 1);
	}
}

int main()
{
	cout << "\n\n" << "1   ";
	FibonacciSeriesUsingRecursion(0, 1, 10);

	system("pause>0");
}