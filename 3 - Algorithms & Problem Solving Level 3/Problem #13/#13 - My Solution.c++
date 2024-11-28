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
			cout  << "  " << setw(2) << Matrix[i][j] << "     ";
		}
		cout << "\n";
	}
}

bool IsIdentityMatrix( int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i != j && Matrix[i][j] != 0)
			{
				return 0;
			}

		}
	}

	return 1;
}

int main()
{
	
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix,3,3);
	cout << "Matrix : " << "\n\n";
	PrintMatrix(Matrix, 3, 3);


	if (IsIdentityMatrix(Matrix, 3, 3))
	{
		system("color 2f");
		cout << "\n\n" << "Yes: it's an Identity Matrix ." << endl;
	}
	else
	{
		system("color 4f");
		cout << "\n\n" << "No: The Matrix is NOT Identity ." << endl;
	}
	

	system("pause > 0");
}