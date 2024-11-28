#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(short From, short To)
{
	short randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d      ",2,arr[i][j]);
		}
		cout << "\n";
	}
}

int SumMatrix(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			sum = sum + arr[i][j];
		}
	}

	return sum;
}

int main()
{
	system("color 5f");

	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "Matrix 1 : " << "\n";
	PrintMatrix(arr, 3, 3);

	cout << "\n\n" << "Sum of Matrix 1 is : " << SumMatrix(arr, 3, 3) << endl;


	system("pause > 0");
}