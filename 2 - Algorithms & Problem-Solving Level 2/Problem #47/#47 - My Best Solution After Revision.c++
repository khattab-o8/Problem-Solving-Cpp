#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "\nPlease Enter a Number ? ";
	cin >> Number;

	return Number;
}

int ConvertNumberToInteger(float Number)
{
	return Number * 10;
}

short FractionPartOfNumber(int NumberWithOutFraction)
{
	if (NumberWithOutFraction > 0)
		return NumberWithOutFraction % 10;
	else
	{
		short PositiveFraction = NumberWithOutFraction * -1;
		return PositiveFraction % 10;
	}
}

bool CompareFractionWithOneHalf(short Fraction)
{
	return Fraction >= 5;
}

int MyRoundFunction(float Number)
{
	if (Number == 0)
		return 0;

	if (Number > 0)
	{
		int NumberWithOutFraction = ConvertNumberToInteger(Number);
		short Fraction = FractionPartOfNumber(NumberWithOutFraction);

		if (CompareFractionWithOneHalf(Fraction))
			return (NumberWithOutFraction / 10) + 1;
		else
			return NumberWithOutFraction / 10;
	}
	else 
	{
		int NegativeNumberWithOutFraction = ConvertNumberToInteger(Number);
		short Fraction = FractionPartOfNumber(NegativeNumberWithOutFraction);

		if (CompareFractionWithOneHalf(Fraction))
			return (NegativeNumberWithOutFraction / 10) - 1;
		else
			return NegativeNumberWithOutFraction / 10;
	}
}

int main()
{
	float Number = ReadNumber();

	cout << "\n\nOutput :- ";

	cout << "\nMy Round Result : " << MyRoundFunction(Number);
	cout << "\nC++ Round Result : " << round(Number);


	system("pause > 0");
	return 0;
}