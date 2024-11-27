#include <iostream>
#include <string>
using namespace std;

void FillArray(int arr[10], int& Length)
{
	Length = 6;

	arr[0] = 10;
	arr[1] = 333;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

}

bool CheckIsItPalindrom(int arr[10], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		if (arr[i] != arr[Length - 1 - i])
		{
			cout << "\nNo, Array is not Palindrome. \n";
			return false;
		}	
	}
	return true;
}

int main()
{
	int arr[10], arrLength = 0;

	FillArray(arr, arrLength);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	if (!CheckIsItPalindrom(arr, arrLength))
	{
		return false;
	}
	else
	{
		cout << "\nyes, Array is Palindrome. \n";
	}

	return 0;
}