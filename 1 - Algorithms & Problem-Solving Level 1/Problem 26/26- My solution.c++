#include <iostream>
#include <string>
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

void PrintNumbersFrom1_To_N_usingForLoop(int Number)
{
	printf("\nNumbers from 1 to %d using For Loop are : \n\n", Number);

	for (int i = 1; i <= Number; i++)
	{
		cout << i << endl;
	}

}

void PrintNumbersFrom1_To_N_usingWhileLoop(int Number)
{
	printf("\nNumbers from 1 to %d using While Loop are : \n\n", Number);

	int counter = 1;

	while (counter <= Number)
	{
		cout << counter << endl;
		counter++;
	}
}

void PrintNumbersFrom1_To_N_usingDoWhileLoop(int Number)
{
	printf("\nNumbers from 1 to %d using Do While Loop are : \n\n", Number);


	int counter = 0;

	do
	{
		counter++;
		cout << counter << endl;
		
	} while (counter < Number);


}

int main()
{
	int Number = 
	ReadPositiveNumber("Please enter a positive Number ?");
	PrintNumbersFrom1_To_N_usingForLoop(Number);
	PrintNumbersFrom1_To_N_usingWhileLoop(Number);
	PrintNumbersFrom1_To_N_usingDoWhileLoop(Number);

	return 0;
}