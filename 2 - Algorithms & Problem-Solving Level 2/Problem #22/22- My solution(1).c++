#include <iostream>
#include <string>
using namespace std;

short ReadPositiveNumber(string Massage)
{
	short Number = 0;
	do
	{
		cout << Massage ;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

void ReadArray(int arr[100],int arrlength)
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
    CheckNumber = ReadPositiveNumber("Enter the number you want to check :");

	return CheckNumber;
}

void PrintOutPut(int arr[100],int arrlength,int CheckNumber)
{
	cout << "Output : " << endl;
	cout << "Original array : ";

	int counter = 0;

	for (int i = 0; i < arrlength; i++)
	{
		cout << arr[i];
		if (arr[i] == CheckNumber)
		{
			counter += 1;
		}

	}

	cout << CheckNumber << " is repeated " << counter << " times(s)" << endl;
}

int main()
{
	int arr[100], arrlength = 0;
	int CheckNumber = ReadCheckNumber();


	ReadArray(arr, arrlength);
	cout << ReadCheckNumber() << endl;
	PrintOutPut(arr, arrlength, CheckNumber);


	return 0;
	
}