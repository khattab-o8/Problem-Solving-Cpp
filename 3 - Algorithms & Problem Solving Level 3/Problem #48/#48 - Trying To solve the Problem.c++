#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double Balance;
};

vector <string> SplitString(string S, string delim)
{
	vector <string> vString;
	string sWord = "";     short Pos = 0;

	while ((Pos = S.find(delim)) != std::string::npos )
	{
		sWord = S.substr(0, Pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, Pos + delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}
	return vString;
}

string TransferDataLineFromFileToStringRecord(string FileName)
{
	string DataLine = "";

	fstream MyFile;
	MyFile.open(FileName, ios::in); //Read Mode.

	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile,line))
		{
			DataLine += line;
		}
		MyFile.close();
	}
	return DataLine;
}

sClient AddClientRecord()
{
	vector <string> vString;
	vString = SplitString(TransferDataLineFromFileToStringRecord(ClientsFileName), "  _*##*_  ");

	sClient Client;

	Client.AccountNumber = vString[0];
	Client.PinCode = vString[1];
	Client.Name = vString[2];
	Client.Phone = vString[3];
	Client.Balance = stod(vString[4]);

	return Client;
}

string NumberOfTabs(short Num)
{
	string Tabs = "";
	for (short i = 1; i <= Num; i++)
	{
		Tabs += "\t";
	}
	return Tabs;
}

void ClientList()
{
	sClient Client;
	Client = AddClientRecord();

	cout << "\n" << NumberOfTabs(6);
	cout << "Client List (" << 0 << ") Client(s)." << endl;

	cout << "________________________________________________________________________________________________________________________" << "\n\n";

	cout << "|" << " Account Number " << setw(2) << "  |" << " Pin Code " << setw(4) << " |" << " Client Name " << setw(37) << "  | " <<  "Phone " << setw(12) << " | "  << "Balance" << setw(2) << "\n";
	cout << "________________________________________________________________________________________________________________________" << endl << endl;

	cout << "| " << Client.AccountNumber << setw(15) << "  | " << Client.PinCode << setw(10) << " | " <<  Client.Name << setw(30) << "  | "  << Client.Phone << setw(7) << " | " << Client.Balance << setw(5) << endl << endl;

	cout << "________________________________________________________________________________________________________________________" << "\n\n";

}

int main()
{
	short counter = 0;

	ClientList();

	system("pause>0");
}