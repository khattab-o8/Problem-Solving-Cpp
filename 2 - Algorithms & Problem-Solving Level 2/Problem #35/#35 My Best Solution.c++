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

bool CheckNumberFoundInArrayOrNot(short NumberPosition)
{
		if (NumberPosition == -1)
		{
			system("color 8F");
			cout << "\nNo, The number is not found :-( \n";
			return true;
		}
	
	return false;
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


	short NumberPosition = FindPositionInArray(arr, arrLength, Number);

	if (CheckNumberFoundInArrayOrNot(NumberPosition))
		return true;
	else
		system("color 5F");
		cout << "\nyes, The number is found :-) \n";

	return 0;
}