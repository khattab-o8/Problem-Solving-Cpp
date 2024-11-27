#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nEnter number of elements:\n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)
		arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";

	cout << "\n";
}

int ReadNumber()
{
	int Number = 0;
	cout << "\nPlease enter a number to search for ?\n";
	cin >> Number;

	return Number;
}

short FindPositionInArray(int arr[100], int arrLength, int Number)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
		{
			return i;
		}
	}

	return -1;
}

bool IsNumberInArray(int arr[100], int arrLength, int Number)
{
	return FindPositionInArray(arr, arrLength, Number) != -1;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray 1 elements :\n";
	PrintArray(arr, arrLength);

	int Number = ReadNumber();
	cout << "\nNumber you are looking for is : " << Number << "\n";

	if (!IsNumberInArray(arr, arrLength, Number))
		cout << "\nNo, The number is not found :-( \n";
	else
		cout << "\nyes, The number is found :-) \n";

	return 0;
}