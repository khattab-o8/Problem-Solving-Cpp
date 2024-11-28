#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string LineRecord, string Separator )
{
	vector <string> vString;
	short Pos = 0;    string sWord = "";

	while ((Pos = LineRecord.find(Separator)) != std::string::npos)
	{
		sWord = LineRecord.substr(0, Pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		LineRecord.erase(0, Pos + Separator.length());
	}
	if (LineRecord != "")
	{
		vString.push_back(LineRecord);
	}
	return vString;
}

stClient StoreClientdataToStructure(string LineRecord, string Separator = "#//#")
{
	vector <string> vClient = SplitString(LineRecord, Separator);
	stClient Client;

	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);

	return Client;
}

void PrintClientRecord(stClient Client)
{

	cout << "\nThe following is the extracted client record: \n\n";

	cout << "Account Number    : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone           : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;

}

int main()
{
	system("color 4f");

	string LineRecord = "A150#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";

	cout << "Line Record is: " << endl;
	cout << LineRecord << endl;

	stClient Client = StoreClientdataToStructure(LineRecord);

	PrintClientRecord(Client);


	system("pause>0");
	
}