#include <iostream>
#include <string>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			printf("  %d      ", Matrix[i][j]);
		}
		printf("\n");
	}
}

bool IsPalindromeMatrix(int Matrix[3][3],short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols/2; j++)
		{
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int Matrix[3][3] = { 
	{ 1, 2, 1 },
	{ 5, 5, 5 },
	{ 7, 3, 6 }};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	if (IsPalindromeMatrix(Matrix, 3, 3))
		cout << "\nYes: Matrix is Palindrome.\n";
	else
		cout << "\nNo: It is NOT a Palindrome Matrix.\n";
	

	system("pause > 0");
	return 0;
}


