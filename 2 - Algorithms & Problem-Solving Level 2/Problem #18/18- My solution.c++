#include <iostream>
#include <string>
using namespace std;

string ReadText()
{
	string Name;

	cout << "Please Enter Your Text ? \n";
	getline(cin, Name);

	return Name;
}

string EncryptText(string Text, short EncryptionKey)
{
	for (short i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKey);
	}
	return Text;
}

string DecryptText(string EncryptedText, short EncryptionKey)
{

	for (short i = 0; i < EncryptedText.length(); i++)
	{
		EncryptedText[i] = char((int)EncryptedText[i] - EncryptionKey);
	}

	return EncryptedText;
}

int main()
{
	system("color 2f");

	const short EncryptionKey = 2;

	string Text = ReadText();

	cout << "\n" << "Output: \n";
	cout << "\n" << "Text Before Encryption : " << Text << endl;

	string EncryptedText = EncryptText(Text, EncryptionKey);
	cout << "Text After Encryption : " << EncryptedText << endl;

	string DecryptedText = DecryptText(EncryptedText, EncryptionKey);
	cout << "Text After Decryption : " << DecryptedText << endl;



	system("pause > 0");
}