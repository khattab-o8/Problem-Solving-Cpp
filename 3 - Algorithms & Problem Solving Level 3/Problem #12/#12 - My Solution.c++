#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum enTypicalNotTypical { Typical = 1, NotTypical = 2 };

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

enTypicalNotTypical CheckTypicalMatricies(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return enTypicalNotTypical::NotTypical;
			}
		}
	}

	enTypicalNotTypical::Typical;
}

bool AreTypicalMatricies(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return ( CheckTypicalMatricies(Matrix1, Matrix2, Rows, Cols) == enTypicalNotTypical::Typical );
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

	if (AreTypicalMatricies(Matrix1, Matrix2, 3, 3))
	{
		system("color 2f");
		cout << "\n\n" << "Yes: both matricies are Typical ." << endl;
	}
	else
	{
		system("color 4f");
		cout << "\n\n" << "No: matricies are NOT Typical ." << endl;
	}
	

	system("pause > 0");
}