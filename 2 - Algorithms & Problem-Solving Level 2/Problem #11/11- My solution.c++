#include <iostream>
#include <string>
using namespace std;

enum enPalindromeNotPalindrome { Palindrome = 1, NotPalindrome = 2 };

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

int ReverseNumber(int Number)
{
	int Remainder = 0, ReveredNumber = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		ReveredNumber = ReveredNumber * 10 + Remainder;
	}

	return ReveredNumber;
}

enPalindromeNotPalindrome Compare_2Numbers(int Number, int ReveredNumber)
{
	if (Number == ReveredNumber)
	{
		return enPalindromeNotPalindrome::Palindrome;
	}
	else
	{
		return enPalindromeNotPalindrome::NotPalindrome;
	}
}

void PrintOutPut(int Number, int ReveredNumber)
{
	switch (Compare_2Numbers(Number, ReveredNumber))
	{
	case enPalindromeNotPalindrome::Palindrome:
		cout << "\nyes, it is a Palindrome number. " << endl;
		break;

	case enPalindromeNotPalindrome::NotPalindrome:
		cout << "\nNo, it is NOT a Palindrome number. " << endl;
		break;
	}
}


int main()
{
	int Number = ReadPositiveNumber("Please enter a positive Number ?");
	int ReveredNumber = ReverseNumber(Number);

	PrintOutPut(Number, ReveredNumber);

	return 0;
}
