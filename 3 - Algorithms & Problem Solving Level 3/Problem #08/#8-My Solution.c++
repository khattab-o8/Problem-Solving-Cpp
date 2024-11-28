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

void Multiply2Matricies(int arrResult[3][3], int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrResult[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[3][3], arr2[3][3], arrResult[3][3];

	FillMatrixWithRandomNumbers(arr1, 3, 3);
	cout << "Matrix 1 : " << "\n";
	PrintMatrix(arr1, 3, 3);


	FillMatrixWithRandomNumbers(arr2, 3, 3);
	cout << "\n\n" << "Matrix 2 : " << "\n";
	PrintMatrix(arr2, 3, 3);


	Multiply2Matricies(arrResult, arr1, arr2, 3, 3);
	cout << "\n\n" << "Results : " << "\n";
	PrintMatrix(arrResult, 3, 3);


	system("pause > 0");
}