#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance;
};

stClient ReadClientData()
{
	stClient Input;

	cout << "Enter Account Number? ";
	cin.ignore(1, '\n');
	getline(cin, Input.AccountNumber);

	cout << "Enter PinCode? "; getline(cin, Input.PinCode);
	cout << "Enter Name? "; getline(cin, Input.Name);
	cout << "Enter Phone? "; getline(cin, Input.Phone);
	cout << "Enter Account Balance? "; cin >> Input.AccountBalance;

	return Input;
}

string ConvertRecordToLine(stClient Client, string Separator = "  _*##*_  ")
{
	string Clientrecord = "";

	Clientrecord += Client.AccountNumber + Separator;
	Clientrecord += Client.PinCode + Separator;
	Clientrecord += Client.Name + Separator;
	Clientrecord += Client.Phone + Separator;
	Clientrecord += to_string(Client.AccountBalance);

	return Clientrecord;
}

vector <string> vString(string Clientrecord)
{
	vector <string> Vclient;
	 Vclient.push_back(Clientrecord);

	 return Vclient;
}

void SaveVectorToFile(vector <string> Vclient,string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios :: app); //Append Mode.

	if (MyFile.is_open())
	{
		//ranged loop
		for (string& line : Vclient)
		{
			if (line != " ")
			{
				MyFile << line << endl;
			}
		}

		MyFile.close();
	}
}


void ResetScreen()
{
	system("cls");
	system("color 4F");
}

void AddingClients()
{
	char AddMore ;

	do
	{
		ResetScreen();

		cout << "Adding New Client: \n\n";

		stClient Client = ReadClientData();
		SaveVectorToFile(vString(ConvertRecordToLine(Client)), " New Clients .txt ");

		cout << "\n\nClient Added Successfully, do you want to add more clients? ";
		cin >> AddMore;

	} while (AddMore == 'y' || AddMore == 'Y');
}

int main()
{
	AddingClients();

	system("pause>0");
}