#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string ClientsFileName = "Clients.txt";

string ReadClientAccountNumber()
{
	string Acc_Number = "";
	cout << "Please enter Account Number ? ";
	cin >> Acc_Number;

	return Acc_Number;
}

struct sClient
{
	string AccountNumber;
	string pinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string S, string delim)
{
	vector <string> vString;
	short pos = 0;            string sWord = "";
	while ((pos = S.find(delim)) != std::string::npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}
	return vString;
}

sClient CovertLineTorecord(string S, string Separator = "#//#")
{
	sClient ClientRecord;
	vector <string> vString;

	vString = SplitString(S, Separator);

	ClientRecord.AccountNumber = vString[0];
	ClientRecord.pinCode = vString[1];
	ClientRecord.Name = vString[2];
	ClientRecord.Phone = vString[3];
	ClientRecord.AccountBalance = stod (vString[4]);

	return ClientRecord;
}

vector <sClient> LoadDataFromFile(string FileName)
{
	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in); //read Mode.

	if (MyFile.is_open())
	{
		string Line;
		sClient sClient;

		while (getline(MyFile, Line))
		{
			sClient = CovertLineTorecord(Line);
			vClients.push_back(sClient);
		}
		MyFile.close();
	}

	return vClients;
}

void PrintClientDetails(sClient sClient)
{

	cout << "\n\n" << "The following are the client details:" << "\n\n";

	cout << "Account Number  : " << sClient.AccountNumber;
	cout << "\nPin Code        : " << sClient.Phone;
	cout << "\nName            : " << sClient.Name;
	cout << "\nPhone           : " << sClient.Phone;
	cout << "\nAccount Balance : " << sClient.AccountBalance;

	cout << "\n\n";
}

bool IsClientAcc_NumberExist(string ClientAcc_Num, vector <sClient> vClients)
{
	//ranged loop.
	for (sClient& sClient : vClients)
	{
		if (sClient.AccountNumber == ClientAcc_Num)
		{
			system("color 2f");
			PrintClientDetails(sClient);
			return true;
		}
	}
	return false;
}

int main()
{
	vector <sClient> vClients;

	string ClientAcc_Num = ReadClientAccountNumber();
	vClients = LoadDataFromFile(ClientsFileName);

	if (IsClientAcc_NumberExist(ClientAcc_Num, vClients))
	{
		return true;
	}
	else
		system("color 4f");
		cout << "\n" << "Client with Account Number (" << ClientAcc_Num << ") Not Found!!\n\n";
		return false;

	system("pause > 0");

}