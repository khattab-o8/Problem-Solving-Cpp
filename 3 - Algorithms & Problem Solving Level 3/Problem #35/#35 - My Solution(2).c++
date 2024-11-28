#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
	string S = " ";

	cout << "\nPlease Enter Your String ? \n";
	getline(cin, S);

	return S;
}

vector <string> SplitString(string S, string Delim = " ")
{
	vector <string> vString;
	short pos = 0;      string sWord = " ";

	while ((pos = S.find(Delim)) != std::string::npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S.erase(0 , pos + Delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}

	return vString;
}

void PrintStringWords(vector <string> vString)
{
	cout << "\n\nYour String Words are: \n\n";

	//ranged loop.

	for (string& word : vString)
	{
		cout << word << endl;
	}
}

int main()
{
	string S = ReadString();
	vector <string> vString = SplitString(S);

	PrintStringWords(vString);

	system("pause>0");
}