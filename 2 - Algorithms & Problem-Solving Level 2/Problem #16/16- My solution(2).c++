#include <iostream>
#include <string>
using namespace std;

void PrintAllWoedsFromA_Z()
{
	
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int c = 65; c <= 90; c++)
			{
				cout << char(i) << " " << char(j) << " " << char(c) << "\n"; 
			}
			cout << "******" << endl; 

		}
	}
}

int main()
{
	PrintAllWoedsFromA_Z();

	return 0;
}