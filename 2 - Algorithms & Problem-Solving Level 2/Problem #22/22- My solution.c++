#include <iostream>
#include <string>
using namespace std;

short ReadPositiveNumber(string Massage)
{
	short Number = 0;
	do
	{
		cout << Massage << endl;
		cin >> Number;

	} while (Number <= 0);

	return Number;
}

string ArrayOfElements(short Number)
{
	cout << "\nEnter array elements : \n";
	int Container = 0;
	string Elements = "";

	for (int i = 1; i <= Number ; i++)
	{
		cout << "Element [" << i << "] : ";
		cin >> Container;

		Elements = Elements + to_string(Container);
		
	}
	cout << "\n";

	return Elements;
}

void OutPut(string Elements)
{
	short CheckNumber = 0, counter = 0;

	cout << "\nEnter the Number you want to check : ";
	cin >> CheckNumber;

	cout << "\nOutput : \n\n";
	cout << "Original array : " << Elements << "\n\n";

	

	for (int j = 0; j <= Elements.length(); j++)
	{
		if ((int)Elements[j] == CheckNumber)
		{
			counter = counter + 1;
		}
	}

	cout << CheckNumber << " is repeated " << counter << " time(s)" << endl;


}


int main()
{

	OutPut(ArrayOfElements(ReadPositiveNumber("Input:")));

	return 0;
	
}