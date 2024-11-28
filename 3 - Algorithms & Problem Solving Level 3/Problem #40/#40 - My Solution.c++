#include <string>
#include <iostream>
#include <vector>
using namespace std;

string JoinString(vector <string>& vString, string delim)
{
	string S1 = " ";
	for (string sWord : vString)
	{
		S1 = S1 + sWord + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

string JoinString(string arr[4], short arrlength, string delim)
{
	string S1 = " ";
	for (short i = 0; i < arrlength; i++)
	{
		S1 = S1 + arr[i] + delim;
	}

	return S1.substr(0, S1.length() - delim.length());
}

int main()
{
	system("color 1f");

	vector <string> vString { "Mohammed", "Faid" , "Ali", "Maher" };
	string arr[4]{ "Mohammed", "Faid" , "Ali", "Maher" };

	cout << "------------>Function Overloading<-------------";

	cout << "\n\n"  << "Vector after join:" << endl;
	cout << JoinString(vString, "  ->#<-  ");

	cout << "\n\n" << "Array after join:" << endl;
	cout << JoinString(arr,4, "  ->#<-  ");


	system("pause>0");
}