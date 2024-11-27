#include <iostream>
#include <string>
using namespace std;

void PrintAllWoedsFromA_Z()
{
	
	for (int i = 65; i <= 90; i++)
	{
		cout << "Letter : " << char(i) << "\n";

		for (int j = 65; j <= 90; j++)
		{
			cout << char(i) << " " << char(i) << " " << char(j) << "\n";

		}
		cout << "******" << endl;
	}
}

int main()
{
	PrintAllWoedsFromA_Z();

	return 0;
}
