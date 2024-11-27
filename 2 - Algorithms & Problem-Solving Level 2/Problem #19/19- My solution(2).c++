#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void PrintRandomNumbers()
{
	cout << "\nOutPut:\n";
	for (short i = 1; i <= 3; i++)
	{
		cout << RandomNumber(1, 10) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	PrintRandomNumbers();

	system("pause>0");
}