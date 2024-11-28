#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string>& vString, string delim)
{
	string S1;

	//ranged loop.
	for (string& Word : vString)
	{
		S1 = S1 + Word + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

int main()
{
	vector <string> vString{ "Mohamed", "Faid" , "Ahmed" , "Lama" };

	cout << "Vector after join: \n\n";
	cout << JoinString(vString, " ** && ** ");


	system("pause>0");
}