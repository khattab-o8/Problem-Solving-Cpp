#include <iostream>
#include <string>
using namespace std;

void ReadArray(int arr[100],int &arrlength)
{
	cout << "Please enter Number of elements in array ? \n";
	cin >> arrlength;

	cout << "\nEnter array elements : \n\n";

	for (int i = 0; i < arrlength; i++)
	{
		cout << "Element [" << i + 1 << "] : ";
		cin >> arr[i];
	}
	cout << "\n";
}

int ReadCheckNumber()
{
	int CheckNumber = 0;
	cout << "Enter the number you want to check : ";
	cin >> CheckNumber;
   
	return CheckNumber;
}

void PrintOutPut(int arr[100],int arrlength,int CheckNumber)
{
	cout << "\nOutput : " << endl;
	cout << "\nOriginal array : ";

	int counter = 0;

	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i] << " ";
		if (arr[i] == CheckNumber)
		{
			counter += 1;
		}

	}

	cout << "\n\n" << CheckNumber << " is repeated " << counter << " times(s)" << endl;
}

int main()
{
	int arr[100], arrlength = 0;

	ReadArray(arr, arrlength);
	PrintOutPut(arr, arrlength, ReadCheckNumber());


	return 0;
	
}