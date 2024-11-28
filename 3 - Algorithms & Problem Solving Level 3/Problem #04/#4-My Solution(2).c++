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
			cout << setw(3) << Matrix[i][j] << "     ";
		}
		cout << "\n\n";
	}
}

int ColumnSum(int Matrix[3][3], short Rows, short ColmNumber)
{
	int sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		sum += Matrix[i][ColmNumber];
	}

	return sum;
}

void PrintColumnSum(int Matrix[3][3], short Rows, short Cols)
{
	cout << "\nThe the following are the sum of each Column in the matrix:\n\n";

	for (short j = 0; j < Cols; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << ColumnSum(Matrix, 3, j) << endl;
	}
}

int main()
{
	srand((unsigned) time(NULL));
	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix: \n\n";
	PrintMatrix(Matrix, 3, 3);

	PrintColumnSum(Matrix, 3, 3);

	system("pause > 0 ");

}