#include <iostream>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{
	int counter = 0 , Number = 0;
	do
	{
		cout << "\nPlease enter a number ? ";
		cin >> arr[counter];
		counter++;
		cout << "\nDo you want to add more numbers ? [0]:No,[1]:yes? ";
		cin >> Number;

	} while (Number == 1);

	arrLength = counter;
}

void PrintArray(int arr[100], int arrLength)
{
	cout << "\nArray Length : " << arrLength;
	cout << "\nArray elements : ";

	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";
}

int main()
{
	int arr[100], arrLength = 0;

	FillArray(arr, arrLength);
	PrintArray(arr, arrLength);

	return 0;
}