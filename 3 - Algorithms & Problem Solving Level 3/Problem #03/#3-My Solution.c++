#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "      ";
		}
		cout << endl;
	}
}

int RowSum(int Matrix[3][3], short RowNumber, short Cols)
{
	int sum = 0;

	for (short j = 0; j < Cols; j++)
	{
		sum += Matrix[RowNumber][j];
	}

	return sum;
}

void FillArrayWithEachMatrixRowSum(int arr[3], short arrlength ,int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < arrlength; i++)
	{
		arr[i] = RowSum(Matrix,i, Cols);

	}
}

void PrintArray(int arr[3], short arrlength)
{
	
	cout << "\nThe the following are the sum of each row in the matrix:\n\n";

	for (short i = 0; i < arrlength; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned) time (NULL));
	int Matrix[3][3],  arr[3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix: \n\n";
	PrintMatrix(Matrix, 3, 3);

	FillArrayWithEachMatrixRowSum(arr,3, Matrix,3,3);

	PrintArray(arr, 3);

	system("pause > 0 ");
}