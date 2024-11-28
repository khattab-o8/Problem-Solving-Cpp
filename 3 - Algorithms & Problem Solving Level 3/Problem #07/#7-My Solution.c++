#include <iostream>
#include <string>
using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols)
{
	short counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			counter++;
			Matrix[i][j] = counter;
		}
	}
}

void TransposeMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			counter++;
			Matrix[j][i] = counter;
		}
	}
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << Matrix[i][j] << "     ";
		}
		cout << "\n";
	}
}

int main()
{
	int Matrix[3][3];

	FillMatrixWithOrderedNumbers(Matrix, 3, 3);
	cout << "\n" << "The following is a 3x3 ordered matrix:" << "\n";
	PrintMatrix(Matrix, 3, 3);

	TransposeMatrix(Matrix, 3, 3);
	cout << "\n\n" << "The following is the transposed matrix:" << "\n";
	PrintMatrix(Matrix, 3, 3);


	system("pause > 0");
}