#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Massage)
{
	int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int Frpm, int To)
{
	int randNum = rand() % (To - Frpm + 1) + Frpm;

	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1,100);
	}
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

bool CheckArrayNumber(int arr[100], int arrLength, int CheckarrNumber)
{
	cout << "\n";

	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == CheckarrNumber)
		{
			system("color 2F");
			cout << "Number you are looking for is : " << CheckarrNumber << "\n";
			cout << "The Number found at position : " << i << "\n";
			cout << "The Number found its order : " << i + 1 << "\n";
			return true;
		}
	}
	
	return false;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0, CheckarrNumber = 0;
	arrLength = ReadPositiveNumber("Please enter array elements ?");

	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	CheckarrNumber = ReadPositiveNumber("\nPlease enter a number to search for ?");
	if (CheckArrayNumber(arr, arrLength, CheckarrNumber))
	{
		return true;
	}
	else
	{
		system("color 4F");
		cout << "Number you are looking for is : " << CheckarrNumber << "\n";
		cout << "The Number is not found :-( " << "\n";
	}


	return 0;
}

