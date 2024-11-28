#include <string>
#include <iostream>
using namespace std;

string ReadString()
{
	string S1;
	cout << "\nPlease Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

short CountEachWordInString(string S1)
{
	short counter = 0, Pos = 0;

	string delim = " ", sWord;

	while ((Pos = S1.find(delim)) != std :: string :: npos )
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			counter++;
		}

		S1.erase(0, Pos + delim.length());
	}

	if (S1 != "")
	{
		counter++;
	}

	return counter;
}


int main()
{
	string S1 = ReadString();

	cout << "\nThe number of words in your string is: ";
	cout << CountEachWordInString(S1);

	system("pause>0");
}