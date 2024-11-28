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
	string sText;

	while ((Pos = S1.find(delim)) != std::string::npos )
	{
		sText = S1.substr(0, Pos);
		if (sText != "")
		{
			vWord.push_back(sText);
		}

		S1.erase(0, Pos + delim.length());
	}

	if (S1 != "")
	{
		vWord.push_back(S1);
	}
	return vWord;
}

void PrintVector(vector <string> vWord)
{
	cout << "\n";
	//ranged loop.
	for (string& Word : vWord)
	{
		cout << Word << endl;
	}
}

int main()
{
	system("color D");
	//string S1 = ReadString();

	string S2 = "Ahmed#**#Lama#**#Jana#**#Dina#**#Fahd";
	vector <string> vWord = SplitString(S2, "#**#");

	cout << "\nTokens = " << vWord.size();
	PrintVector(vWord);

	system("pause>0");
}