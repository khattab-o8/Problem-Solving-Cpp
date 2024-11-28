#include <iostream>
#include <string>
using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3])
{
	short counter = 1;

	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			Matrix[i][j] = counter;
			counter++;
		}
	}
}

void PrintMatrix(int Matrix[3][3])
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			cout << "  " << Matrix[i][j] << "     ";
		}
		cout << endl;
	}
}

int main()
{
	int Matrix[3][3];

	FillMatrixWithOrderedNumbers(Matrix);

	cout << "\nThe Following is a 3x3 ordered matrix: \n";
	PrintMatrix(Matrix);


	system("pause > 0");
	return 0;
}