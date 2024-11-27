#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], short& arrLength)
{
	cout << "Please Enter Number Of Elements in array ? " << endl;
	cin >> arrLength;

	for (short i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int arr[100], short arrLength)
{
	cout << "Array Elements: ";

	for (short i = 0; i < arrLength; i++)
	{
		cout << arr[i] << "  ";
	}

	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	system("color D");


	int arr[100];  short arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\n\n" << "Output:" << "\n";
	PrintArray(arr, arrLength);


	system("pause>0");
}