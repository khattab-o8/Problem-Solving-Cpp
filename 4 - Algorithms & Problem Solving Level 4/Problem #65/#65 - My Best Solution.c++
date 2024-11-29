#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

short ReadNumber()
{
	short Number = 0;
	do
	{
		cout << "\nPlease, Chooose Your Date Formate ? ";
		cin >> Number;

	} while (Number < 1 || Number > 6);

	return Number;
}

vector <string> SplitString(string DateString, string Delim)
{
	vector <string> vString;

	short pos = 0;   string sWord = "";

	while ((pos = DateString.find(Delim)) != std::string::npos)
	{
		sWord = DateString.substr(0,pos);
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

enum enDateFormats 
{
	DayFirstwithForwardSlash = 1,
    YearFirstwithForwardSlash = 2,
	MonthFirstwithForwardSlash = 3,
	MonthFirstwithDash = 4,
	DayFirstwithDash = 5,
	Day_Momth_Year_WithColumn = 6
};

void FormatType()
{
	cout << "\n";
	cout << "\t" << "_______________________________\n";
	cout << "\t" << setw(27) << left << "1- dd/mm/yyyy" << "\n";
	cout << "\t" << setw(27) << left << "2- yyyy/dd/mm" << "\n";
	cout << "\t" << setw(27) << left << "3- mm/dd/yyyy" << "\n";
	cout << "\t" << setw(27) << left << "4- mm-dd-yyyy" << "\n";
	cout << "\t" << setw(27) << left << "5- dd-mm-yyyy" << "\n";
	cout << "\t" << setw(27) << left << "6- Day:dd, Month:mm, Year:yyyy\n";
	cout << "\t" << "_______________________________\n";
}    

void DateFormat(stDate Date, enDateFormats DateFormats)
{
	cout << "\nOutput : ";

	switch (DateFormats)
	{
	case enDateFormats::DayFirstwithForwardSlash:
		cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
		break;

	case enDateFormats::YearFirstwithForwardSlash:
		cout << Date.Year << "/" << Date.Day << "/" << Date.Month;
		break;

	case enDateFormats::MonthFirstwithForwardSlash:
		cout << Date.Month << "/" << Date.Day << "/" << Date.Year;
		break;

	case enDateFormats::MonthFirstwithDash:
		cout << Date.Month << "-" << Date.Day << "-" << Date.Year;
		break;

	case enDateFormats::DayFirstwithDash:
		cout << Date.Day << "-" << Date.Month << "-" << Date.Year;
		break;

	case enDateFormats::Day_Momth_Year_WithColumn:
		cout << "Day:" << Date.Day << ", " << "Month:" << Date.Month << ", " << "Year:" << Date.Year;
		break;
	}
}

int main()
{
	system("color 4f");

	string DateString;
	DateString = ReadDateString();

	FormatType();

	stDate Date;
	Date = StringToDate(DateString);

	DateFormat(Date, (enDateFormats)ReadNumber());

	system("pause>0");
	return 0;
}