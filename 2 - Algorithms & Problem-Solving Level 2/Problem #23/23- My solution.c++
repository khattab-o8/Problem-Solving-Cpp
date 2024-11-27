#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Massage)
{
	int Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

int RandomNumber(int From, int To)
{
	int randnum = rand() % (To - From + 1) + From;

	return randnum;
}

int GenerateWord(int arr[100])
{
	for (int i = 1; i <= 2; i++)
	{
		arr[100] = RandomNumber(48, 57);
	}
	return arr[100];
}

void GenerateArray(int arr[100],int Number)
{
	cout << "\nOutput: " << "\n";
	cout << "Array Elements : ";
	for (int i = 0; i < Number; i++)
	{
		cout << GenerateWord(arr) << " ";
	}
}

int main()
{
	srand ((unsigned) time (NULL));
	int arr[100];

	GenerateArray(arr, ReadPositiveNumber("Please enter Number of elemnts in array ? "));


	return 0;	
}