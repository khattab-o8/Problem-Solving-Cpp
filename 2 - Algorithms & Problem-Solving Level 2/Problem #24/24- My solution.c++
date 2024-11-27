#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillArrayWithRandomNumber(int arr[100], short &arrLength)
{
	cout << "Enter Number of elements in array ?\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);

	}
}

void PrintArray(int arr[100], short arrLength)
{
	cout << "\nOutPut : \n";
	cout << "\nArray Elements : ";

	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int MaxArrayNumber(int arr[100], short arrLength)
{
	int Max = 0;

	for (int i = 0; i < arrLength; i++)
	{
		Max = max(arr[i], arr[arrLength - 1]);
	}
	return Max;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100];  short arrLength;

	FillArrayWithRandomNumber(arr, arrLength);
	PrintArray(arr, arrLength);
	cout << "\nMax Number is : " << MaxArrayNumber(arr, arrLength) << endl;

	return 0;
}