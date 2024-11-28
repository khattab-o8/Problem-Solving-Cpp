#include <string>
#include <iostream>
#include <cctype>
using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String ? " << endl;
	getline(cin, S1);

	return S1;
}

string To_UpperAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}

	return S1;
}

string To_LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

int main()
{
	string S1 = ReadString();

	cout << "\n" << "String after Upper:" << endl;
	S1 = To_UpperAllString(S1);
	cout << S1 << endl;

	cout << "\n" << "String after Lower:" << endl;
	S1 = To_LowerAllString(S1);
	cout << S1 << endl;



	system("pause>0");
}