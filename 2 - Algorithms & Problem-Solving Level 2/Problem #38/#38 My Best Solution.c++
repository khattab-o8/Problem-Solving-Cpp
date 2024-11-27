#include <iostream>
using namespace std;

enum enOddEven { Odd = 1, Even = 2 };

enOddEven CheckOdd(int Number)
{
	if (Number % 2 != 0)
	{
		return enOddEven::Odd;
	}
	return enOddEven::Even;
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nPlease enter array elements ? \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}

	cout << "\n";
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}
	cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyOnlyOddNumbersUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckOdd(arrSource[i]) == enOddEven::Odd)
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100], arr2Length = 0;
	CopyOnlyOddNumbersUsingAddArrayElement(arr, arr2, arrLength, arr2Length);

	cout << "\nArray 1 Elements : \n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 Odd numbers : \n";
	PrintArray(arr2, arr2Length);


	return 0;
}