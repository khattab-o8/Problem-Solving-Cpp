#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	//Function to generate a random number
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
			printf("  %0*d       ", 2, Matrix[i][j]);
		}
		printf("\n");
	}
}

void PrintMiddleRowOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;
	for (short j = 0; j < Cols; j++)
	{
		printf("  %0*d       ", 2, Matrix[MiddleRow][j]);

	}
}

void PrintMiddleColOfMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	for (short i = 0; i < Rows; i++)
	{
		printf("            %0*d \n\n", 2, Matrix[i][MiddleCol]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "Matrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle Row of Matrix1 is: \n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	cout << "\n\nMiddle Col of Matrix1 is: \n\n";
	PrintMiddleColOfMatrix(Matrix, 3, 3);


	system("pause > 0");
	return 0;
}


