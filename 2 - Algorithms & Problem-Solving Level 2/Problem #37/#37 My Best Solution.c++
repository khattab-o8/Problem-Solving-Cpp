#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

int ReadNumber()
{
	int Number = 0;
	cout << "\nPlease enter array elements ? \n";
	cin >> Number;

	return Number;
}

void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{

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

void AddArrayElement(int arrDestination[100], int& arr2Length, int arrSource[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr2Length++;
		arrDestination[arr2Length - 1] = arrSource[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arrLength = 0;
	arrLength = ReadNumber();

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100], arr2Length = 0;
	AddArrayElement(arr2, arr2Length, arr, arrLength);

	cout << "\nArray 1 Elements : \n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 Elements after copy : \n";
	PrintArray(arr2, arr2Length);


	return 0;
}