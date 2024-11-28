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

void FillMatrixWithRandomNumbers(int Matrix[3][5], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int Matrix[3][5], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "     ";
		}
		cout << endl;
	}
}

int ColmnSum(int Matrix[3][5], short Rows, short ColNumber)
{
	int sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		sum += Matrix[i][ColNumber];
	}

	return sum;
}

void FillArrayWithEachColumnSum(int arrsum[5], int Matrix[3][5], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		arrsum[i] = ColmnSum(Matrix, Rows, i);
	}
}

void PrintArraySum(int arrsum[5], short Cols)
{
	cout << "\nThe the following are the sum of each Column in the matrix:\n\n";

	for (short i = 0; i < Cols; i++)
	{
		cout << " Col " << i + 1 << " Sum = " << arrsum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Matrix[3][5], arrsum[5];

	FillMatrixWithRandomNumbers(Matrix, 3, 5);

	cout << "The following is a 3x3 random matrix: \n\n";
	PrintMatrix(Matrix, 3, 5);

	FillArrayWithEachColumnSum(arrsum, Matrix, 3, 5);
	PrintArraySum(arrsum, 5);

	system("pause > 0");
}