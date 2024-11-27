#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

int ReadPositiveNumber()
{
	int Number = 0;
	do
	{
		cout << "\nPlease Enter Array Length 'only Positive Number' ? ";
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void FillArrayWithRandomNumbers(int arrlength, int arr[100])
{
	for (short i = 0; i < arrlength; i++)
	{
		arr[i] = RandomNumber(1,100);
	}
}

void CopyArrayInReverseOrder(int arrlength, int arrSource[100], int arrDestination[100])
{
	short counter = 0;

	for (short i = 1; i <= arrlength; i++)
	{
		arrDestination[counter] = arrSource[arrlength - i];
		counter++;
	}
}

void PrintArray(int arrlength, int arr[100])
{
	for (short i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arrlength = ReadPositiveNumber();
	int arrSource[100], arrDestination[100];

	FillArrayWithRandomNumbers(arrlength, arrSource);

	cout << "\n\nArray 1 elements: \n";
	PrintArray(arrlength, arrSource);

	CopyArrayInReverseOrder(arrlength, arrSource, arrDestination);

	cout << "\n\nArray 2 elements after copying array 1 in reversed order:\n";
	PrintArray(arrlength, arrDestination);


	system("pause > 0");
	return 0;
}