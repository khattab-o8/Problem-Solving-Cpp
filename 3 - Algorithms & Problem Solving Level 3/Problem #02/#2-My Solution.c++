#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";

		}
		cout << "\n\n";
	}
}

void PrintSumofEachRowInTheMatrix(int arr[3][3], short Rows, short Cols)
{
	int sum = 0;

	for (short i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = ";

		for (short j = 0; j < Cols; j++)
		{
			sum = sum + arr[i][j];
		}
		cout << sum << "\n";
		sum = 0;
	}

	cout << endl;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "The following is a 3x3 random matrix: \n\n";
	PrintMatrix(arr, 3, 3);

	cout << "\n" << "The following are the sum of each row in the matrix: \n\n";
	PrintSumofEachRowInTheMatrix(arr, 3, 3);

	return 0;
}