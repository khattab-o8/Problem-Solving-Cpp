#include <string>
#include <iostream>
using namespace std;

enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

enPrimeNotPrime CheckPrime(int Number)
{
	short M = round(Number / 2);
	for (short i = 2; i <= M; i++)
	{
		if (Number % i == 0)
			return enPrimeNotPrime::NotPrime;
	}

	return enPrimeNotPrime::Prime;
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

void FillArrayWithRandomNumbers(int arr1[100], short arrlength)
{
	for (short i = 0; i < arrlength; i++)
	{
		arr1[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], short arrlength)
{
	for (short i = 0; i < arrlength; i++)
	{
		cout << arr[i] << "  ";
	}
}

void CopyOlyPrimeNumbersToArray2(int arr1[100], int arr2[100], short arrlength , short& arr2length)
{
	short counter = 0;

	for (short i = 0; i < arrlength; i++)
	{
		if (CheckPrime(arr1[i]) == enPrimeNotPrime::Prime)
		{
			arr2[counter] = arr1[i];
			counter++;
		}
	}
	arr2length = --counter;
}

int main()
{
	srand((unsigned)time(NULL));

	system("color 4f");
	int arr1[100], arr2[100];
	short arrlength = 0, arr2length = 0;

	arrlength = ReadPositiveNumber("Please Enter Number of Elements ?");

	FillArrayWithRandomNumbers(arr1, arrlength);

	CopyOlyPrimeNumbersToArray2(arr1, arr2, arrlength, arr2length);

	cout << "\nOutput:\n";
	cout << "\nArray 1 elements: \n";
	PrintArray(arr1, arrlength);

	cout << "\n\n" << "Prime Numbers in Array2: \n";
	PrintArray(arr2, arr2length);


	system("pause>0");
}