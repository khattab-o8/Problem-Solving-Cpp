#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;
	short Pos = 0;   string sWord = "";

	while ((Pos=S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, Pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

vector <string> UpdateRecordInVector(string S1, string Delim, string Record, string UpdateTo)
{
	vector <string> vString = SplitString(S1, Delim);

	//ranged loop.
	for (string& Word : vString)
	{
		if (Word == Record)
		{
			 Word = UpdateTo;
		}
	}

	return vString;
}

string StringAfterUpdateRecord(string S1, string Delim, string Record, string UpdateTo)
{
	vector <string> vString = UpdateRecordInVector(S1, Delim, Record, UpdateTo);
	string S2 = "";
	for (string& Word : vString)
	{
		S2 += Word + Delim;
	}
	S2 = S2.substr(0, S2.length() - Delim.length());

	return S2;
}

int main()
{
	system("color 4f");

	string S1 = "Welcome to Jordan , Jordan is a nice country";

	cout << "Original String";
	cout << "\n" << S1;

	cout << "\n\n" << "String After Replace:";
	cout << "\n" << StringAfterUpdateRecord(S1, " ", "Jordan", "USA");


	system("pause>0");
}