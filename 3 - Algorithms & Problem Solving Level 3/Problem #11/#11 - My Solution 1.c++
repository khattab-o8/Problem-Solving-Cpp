#include <iostream>
#include <string>
#include <cstdlib>
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
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %0*d     ", 2, Matrix[i][j]);
		}
		cout << "\n";
	}
}

int SumOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			sum += Matrix[i][j];
		}	
	}

	return sum;
}

void CheckMatriciesEquality(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	// Short Hand if..else.
	string Result = (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols)) ?
	"Yes: matricies are equal." : "No: matricies are NOT equal.";

	cout << "\n\n" << Result << endl;
}

int main()
{
	
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1,3,3);
	cout << "Matrix 1 : " << "\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\n" << "Matrix 2 : " << "\n";
	PrintMatrix(Matrix2, 3, 3);

	CheckMatriciesEquality(Matrix1, Matrix2, 3, 3);


	system("pause > 0");
}