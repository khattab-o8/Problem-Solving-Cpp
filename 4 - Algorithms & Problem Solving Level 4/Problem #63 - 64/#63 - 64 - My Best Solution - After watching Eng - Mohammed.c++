#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

string ReadDateString()
{
	string DateString = "";
	cout << "\nPlease Enter Date dd/mm/yyyy ? ";
	getline(cin >> ws, DateString);

	return DateString;
}

vector <string> SplitString(string DateString, string Delim)
{
	vector <string> vString;

	short pos = 0;         string sWord = "";

	while ((pos = DateString.find(Delim)) != std::string::npos )
	{
		sWord = DateString.substr(0, pos);
		if (sWord != "") {

			vString.push_back(sWord);
		}

		DateString.erase(0, pos + Delim.length());
	}
	if (DateString != "") {

		vString.push_back(DateString);
	}

	return vString;
}

stDate StringToDate(string DateString, string Separator = "/")
{
	stDate Date;
	vector <string> vString;

	vString = SplitString(DateString, Separator);

	Date.Day = stoi(vString[0]);
	Date.Month = stoi(vString[1]);
	Date.Year = stoi(vString[2]);

	return Date;
}

string DateToString(stDate Date, string Separator = "/")
{
	string DateString = "";

	DateString += to_string(Date.Day) + Separator;
	DateString += to_string(Date.Month) + Separator;
	DateString += to_string(Date.Year);

	return DateString;
}

int main()
{
	string DateString;
	DateString = ReadDateString();

	stDate Date;
	Date = StringToDate(DateString);

	cout << "\nDay : " << Date.Day;
	cout << "\nMonth : " << Date.Month;
	cout << "\nYear : " << Date.Year;

	cout << "\n\nYou Entered : " << DateToString(Date) << endl;


	system("pause>0");
	return 0;
}