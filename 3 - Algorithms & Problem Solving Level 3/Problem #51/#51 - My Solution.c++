#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

string ReadClientAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter Account Number ? ";
	cin >> AccountNumber;

	return AccountNumber;
}

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

sClient ConvertDataLineToRecord(string S1, string Separator = "#//#")
{
	sClient ClientRecord;
	vector <string> vClientData;

	vClientData = SplitString(S1, Separator);

	ClientRecord.AccountNumber = vClientData[0];
	ClientRecord.PinCode = vClientData[1];
	ClientRecord.Name = vClientData[2];
	ClientRecord.Phone = vClientData[3];
	ClientRecord.AccountBalance = stod(vClientData[4]);//cast string to double

	return ClientRecord;
}

vector <sClient> LoadDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in); //read Mode.

	if (MyFile.is_open())
	{
		sClient Client;
		string Line;
		while (getline(MyFile,Line))
		{
			Client = ConvertDataLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number   : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone           : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;
}

sClient UpdateClientrecordByAccountNumber(string AccountNumber)
{
	sClient UpdatedClientRecord;

	UpdatedClientRecord.AccountNumber = AccountNumber;

	cout << "\n\n" << "Enter PinCode? ";
	getline(cin >> ws, UpdatedClientRecord.PinCode);

	cout << "Enter Name? ";
	getline(cin, UpdatedClientRecord.Name);

	cout << "Enter Phone? ";
	getline(cin, UpdatedClientRecord.Phone);

	cout << "Enter Account Balance? ";
	cin >> UpdatedClientRecord.AccountBalance;

	return UpdatedClientRecord;
}

vector <sClient> UpdateClientByAccountnumber(string AccountNumber, vector <sClient>& vClients)
{
	//ranged loop
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C = UpdateClientrecordByAccountNumber(AccountNumber);
			break;
		}
	}

	return vClients;
}

string ConvertRecordToDataLine(sClient client, string Separator = "#//#")
{
	string DataLine = "";

	DataLine += client.AccountNumber + Separator;
	DataLine += client.PinCode + Separator;
	DataLine += client.Name + Separator;
	DataLine += client.Phone + Separator;
	DataLine += to_string(client.AccountBalance);

	return DataLine;
}

vector <sClient> CopyDataToFile(string FileName, vector <sClient> vClients)
{
	string DataLine = "";

	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite.

	if (MyFile.is_open())
	{
		//ranged loop.
		for (sClient& Client : vClients)
		{
			DataLine = ConvertRecordToDataLine(Client);
			MyFile << DataLine << endl;
		}
		MyFile.close();
	}

	return vClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	sClient client;
	char answer = 'n';
	if (FindClientByAccountNumber(AccountNumber, vClients, client))
	{
		PrintClientCard(client);

		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			vClients = UpdateClientByAccountnumber(AccountNumber, vClients);
			//Refresh DataFile.
			CopyDataToFile(ClientsFileName, vClients);

			cout << "\n\n";
			cout << "Client Updated Successfully." << endl;
			return true;
		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber << ") Not Found!" << endl;
		return false;
	}
}

int main()
{
	system("color 4f");

	string AccountNumber = ReadClientAccountNumber();
	vector <sClient> vClients = LoadDataFromFile(ClientsFileName);

	UpdateClientByAccountNumber(AccountNumber, vClients);


	system("pause>0");
}