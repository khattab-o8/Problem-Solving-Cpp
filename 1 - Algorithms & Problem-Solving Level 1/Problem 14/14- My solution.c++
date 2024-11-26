#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(short& Number1, short& Number2)
{
	cout << "Please enter Number 1 ? \n";
	cin >> Number1;

	cout << "\nPlease enter Number 2 ? \n";
	cin >> Number2;
}

void SwapNumbers(short& A, short& B)
{
	short Temp = 0;

	Temp = A;
	A = B;
	B = Temp;

}

void PrintNumbers(short Number1, short Number2)
{
	cout << "\nNumber 1 : " << Number1 << "\n";
	cout << "Number 2 : " << Number2 << "\n";
}

int main()
{
	short Number1 = 0, Number2 = 0;
	
	ReadNumbers(Number1, Number2);
	PrintNumbers(Number1, Number2);

	SwapNumbers(Number1, Number2);
	PrintNumbers(Number1, Number2);


	return 0;
}