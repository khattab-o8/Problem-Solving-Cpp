#include <string>
#include <iostream>
#include <vector>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

vector <string> SplitString(string S1, string delim)
{
	vector <string> vWord;
	short Pos = 0;
	string sWord = " ";

	while ((Pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			vWord.push_back(sWord);
		}
		S1.erase(0, Pos + delim.length());
	}
	if (S1 != "")
	{
		vWord.push_back(S1);
	}

	return vWord;
}

string ReverseWords(vector <string>& vWord, string delim)
{
	string Text = " ";
	//reverded ranged loop.
	for (short i = vWord.size() - 1; i >= 0; i--)
	{
		Text = Text + vWord[i] + delim;
	}
	return Text.substr(0, Text.length() - delim.length());
}

int main()
{
	system("color D");

	string S1 = ReadString();
	vector <string> vWord = SplitString(S1, " ");

	cout << "\n\n";
	cout << "String after reversing words: ";
	cout << "\n" << ReverseWords(vWord, " ");

	system("pause>0");
}