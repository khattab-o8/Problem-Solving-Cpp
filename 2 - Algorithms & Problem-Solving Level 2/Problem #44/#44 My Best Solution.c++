#include <iostream>
#include <string>
using namespace std;

enum enPositiveOrNegative { Positive = 1, Negative = 2 };

enPositiveOrNegative CheckNumber(int Number)
{
	if (Number > 0)
	{
		return enPositiveOrNegative::Positive;
	}
	return enPositiveOrNegative::Negative;
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
		arr[i] = RandomNumber(-100 , 100);
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

int CountPositiveNumbers(int arr[100], int arrLength)
{
	int counter = 0;

	for (int i = 0; i < arrLength; i++)
	{
		if (CheckNumber(arr[i]) == enPositiveOrNegative::Positive)
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

	cout << "\nPositive Numbers count is : ";
	cout << CountPositiveNumbers(arr, arrLength) << "\n\n";


	return 0;
}