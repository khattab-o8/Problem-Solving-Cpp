#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], short &arrLength)
{
	cout << "\nPlease enter number of elements in array ?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}

	cout << "\n";
}

void PrintArray1(int arr[100], short arrLength)
{
	cout << "Array 1 Elements : \n";

	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}
	cout << "\n";
}

void FillArray2WithArray1(int arr[100], int arr2[100], short arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr2[i] = arr[i];
	}
}

void PrintArray2_Copy(int arr2[100], short arrLength)
{
	cout << "\nArray 2 elements after copy :\n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr2[i] << " ";

	}

	cout << "\n";
}
	
int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arr2[100];             
	short arrLength;

	FillArrayWithRandomNumbers(arr, arrLength);
	PrintArray1(arr, arrLength);

	FillArray2WithArray1(arr, arr2, arrLength);
	PrintArray2_Copy(arr2, arrLength);

	return 0;
}