#include <iostream>
#include <string>
using namespace std;

void AddArrayElement(int Number, int arr[10], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyDistinctNumbers(int arrSource[10], int arrDestination[10], int& arrDestinationLength)
{
	for (int i = 0; i < 10; i++)
	{
		if (arrSource[i] != arrSource[i+1])
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
	}

}

void PrintArray(int arr[10], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}

int main()
{
	int arr1[10] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };
	int arr2[10], arr2Length = 0;

	CopyDistinctNumbers(arr1, arr2, arr2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr1, 10);

	cout << "\nArray 2 distinct elements : \n";
	PrintArray(arr2, arr2Length);

	return 0;
}