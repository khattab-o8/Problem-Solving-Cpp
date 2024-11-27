#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From,int To)
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

void PrintArray(int arr[100], short arrLength)
{
	cout << "Array Elements : ";

	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}
	cout << "\n";
}

int SumOfArray(int arr[100], short arrLength)
{
	int sum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		sum = sum + arr[i];
	}

	return sum;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[100], short arrLength ;

	FillArrayWithRandomNumbers(arr, arrLength);
	PrintArray(arr, arrLength);
	cout << "\nSum of all number is : " 
	<< SumOfArray(arr, arrLength) << endl;



	return 0;
}