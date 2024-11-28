#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> & vString, string Separator = "__^^__")
{
	string Line = " ";

	//ranged loop.
	for (string& Word : vString)
	{
		Line += Word + Separator;
	}

	return Line.substr(0, Line.length() - Separator.length());
}

int main()
{
	vector <string> vString = { "Mohammed", "Faid", "Ali", "Maher" };

	cout << "\nVector after join: \n\n";

	cout << JoinString(vString);

	system("pause > 0");
	return 0;
}