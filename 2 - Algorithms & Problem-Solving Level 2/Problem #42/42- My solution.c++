#include <iostream>
#include <string>
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

int CountOfOddNimbers(int arr[100], int arrLength)
{
	int counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (CheckOdd(arr[i]) == enOddEven::Odd)
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "Array Elements : ";
	PrintArray(arr, arrLength);

	cout << "\nOdd Numbers count is : ";
	cout << CountOfOddNimbers(arr, arrLength) << "\n\n";


	return 0;
}