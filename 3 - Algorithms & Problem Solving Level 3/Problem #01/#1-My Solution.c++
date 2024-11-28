#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = 0;

	randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillMatrixWithRandomNubers(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Matrix[i][j] = RandomNumber(1,100);
		}
	}
}

void PrintMatrix(int Matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%0*d    ",2, Matrix[i][j]);
		}
		cout << "\n\n";
	}
}


int main()
{
	srand((unsigned) time (NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNubers(Matrix);
	PrintMatrix(Matrix);

	return 0;
}