#include <string>
#include <iostream>
#include <cctype>
using namespace std;

char ReadCharacter()
{
	char C = ' ';

	cout << "Please Enter a Character ? \n";
	cin >> C;

	return C;
}

char InvertCharacter(char C)
{
	if (C >= 97 && C <= 122) // --> small character
		return toupper(C);
	else  // then, its's a capital character
		return tolower(C);
}


int main()
{
	char C = ReadCharacter();

	cout << "\nChar after inverting case: \n";
	C = InvertCharacter(C);
	cout << C << endl;


	system("pause>0");
}