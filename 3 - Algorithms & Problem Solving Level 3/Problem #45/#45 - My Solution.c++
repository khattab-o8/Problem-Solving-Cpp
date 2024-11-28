#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
	string AccountNumber = " ";
	string PinCode = " ";
	string Name;
	string Phone = " ";
	string AccountBalance = " ";
};

void ReadClientData(stClientData& InputData, vector <string>& vString)
{
	cout << "Please Enter Client Data:";

	cout << "\n\n" << "Enter Account Number? ";
	cin >> InputData.AccountNumber;
	vString.push_back(InputData.AccountNumber);

	cout << "Enter PinCode? ";
	cin >> InputData.PinCode;
	vString.push_back(InputData.PinCode);

	cout << "Enter Name? ";
	cin.ignore(1, '\n');
	getline(cin, InputData.Name);
	vString.push_back(InputData.Name);

	cout << "Enter Phone? ";
	cin >> InputData.Phone;
	vString.push_back(InputData.Phone);

	cout << "Enter AccountBalance? ";
	cin >> InputData.AccountBalance;
	vString.push_back(InputData.AccountBalance);
}

string ClientRecord(vector <string> vString, string delim)
{
	string S1 = " ";
	//ranged loop
	for (string& Line : vString)
	{
		S1 = S1 + Line + delim;
	}
	S1 = S1.substr(0, S1.length() - delim.length());

	return S1;
}

int main()
{
	system("color 4f");

	stClientData InputData;
	vector <string> vString;

	ReadClientData(InputData, vString);

	cout << "\n\n\n";
	cout << "Client Record for Saving is: ";
	cout << "\n" << ClientRecord(vString, "#//#");

	system("pause>0");
}