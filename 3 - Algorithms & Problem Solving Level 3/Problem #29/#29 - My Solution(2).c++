#include <iostream>
#include <string>
#include <cctype>
using namespace std;

enum enWhatToCount { CountSmallLetters = 0 , CountCapitalLetters = 1 , CountAll = 2 };

short CountStringLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::CountAll)
{
	if (WhatToCount == enWhatToCount::CountAll)
	{
		return S1.length();
	}

	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CountSmallLetters && islower(S1[i]))
		{
			Counter++;
		}

		if (WhatToCount == enWhatToCount::CountCapitalLetters && isupper(S1[i]))
		{
			Counter++;
		}
	}

	return Counter;
}


string ReadString()
{
	string S1 = "";
	cout << "\nPlease Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

short CountCapitalLettersInString(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			counter++;
		}
	}

	return counter;
}

short CountSmallLettersInString(string S1)
{
	short counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			counter++;
		}
	}

	return counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\n" << "String Length = " << S1.length();

	printf("\nCapital Letters Count = %d \n", CountCapitalLettersInString(S1));

	printf("Small Letters Count = %d \n", CountSmallLettersInString(S1));

        //Second Method

	cout << "\n\n" << "String Length = " << CountStringLetters(S1);

	printf("\nCapital Letters Count = %d \n", CountStringLetters(S1, enWhatToCount::CountCapitalLetters));

	printf("Small Letters Count = %d \n", CountStringLetters(S1, enWhatToCount::CountSmallLetters));





	system("pause > 0");
	return 0;
}