#include <iostream>
#include <string>
using namespace std;

int RabdomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;

}

void ReadArrayLength(int &arrLength)
{
	cout << "\nEnter Array Elements ?\n";
	cin >> arrLength;

}

void FillArrayWithRandomNumbers(int arrSource[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrSource[i] = RabdomNumber(1, 100);

	}

}

void PrintArray(int arrSource[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arrSource[i] << " ";
	}

	cout << "\n";

}

void FillArray3_WithSumOf_Array1andArray2(int arrDestination[100], int arr1[100], int arr2[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{

		arrDestination[i] = arr1[i] + arr2[i];

	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	ReadArrayLength(arrLength);
	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	FillArrayWithRandomNumbers(arr2, arrLength);

	int arr3[100];
	FillArray3_WithSumOf_Array1andArray2(arr3, arr, arr2, arrLength);


	cout << "\nArray 1 elemnts : \n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elemnts : \n";
	PrintArray(arr2, arrLength);

	cout << "\nSum of array1 and array2 elements : \n";
	PrintArray(arr3, arrLength);


	return 0;
}

