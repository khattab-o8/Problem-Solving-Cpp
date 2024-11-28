#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix1[4][4], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << "  " << setw(2) << Matrix1[i][j] << "    ";
		}
		cout << "\n";
	}
}

bool IsPalindromeMatrix(int Matrix1[4][4], short Rows, short Cols)
{
	cout << "\n\n";
	short FirstMatrixElement = Matrix1[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[j][0] != Matrix1[j][Cols - 1])
			{
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int Matrix1[4][4] =
	{
		{1,2,2,1},
		{3,4,4,3},
		{7,9,9,7},
		{8,6,6,8}
	};

	cout << "Matrix1:" << "\n";
	PrintMatrix(Matrix1, 4, 4);

	if (IsPalindromeMatrix(Matrix1, 4, 4))
		cout << "Yes: Matrix is Palindrome \n";
	else
		cout << "No: Matrix is NOT Palindrome \n";


	system("pause>0");
}