#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);
	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
		{
			return enPrimeNotPrime::NotPrime;
		}

	}
	return enPrimeNotPrime::Prime;
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "\nPlease enter How Many array elements ? \n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}

	cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrSourceLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrSourceLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
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

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], arrLength = 0;
	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100], arr2Length = 0;
	CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);

	cout << "\nArray 1 elements : \n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 Prime Numbers : \n";
	PrintArray(arr2, arr2Length);


	return 0;
}