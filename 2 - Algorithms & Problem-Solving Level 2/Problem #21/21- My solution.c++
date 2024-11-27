#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int ReadPositiveNumber(string Massage)
{
    int Number = 0;
    do
    {
        cout << Massage << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;
}

int RandomNumber(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;

    return randnum;
}

string GenerateKey()
{
    string word = "";

    for (int i = 1; i <= 16; i++)
    {
        word = word + char(RandomNumber(65, 90));
    }

    return word;
}

//string DevideGeneratedKeys()
//{
//    string GeneratedKey = GenerateKey(), Char = "-", NewKey;
//
//    for (int i = 0; i <= GeneratedKey.length();i++)
//    {
//        if (GeneratedKey[i] == 4)
//        {
//            NewKey = GeneratedKey[i] + Char;
//
//        }
//    }
//
//    return NewKey;
//}

void PrintGeneratedKeys(short Number)
{
    int counter = 0;

    for (short i = 1; i <= Number; i++)
    {
        counter++;

        cout << "Key [" << counter << "] : " << GenerateKey() << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    PrintGeneratedKeys(ReadPositiveNumber("Please enter a positive Number ?"));


    return 0;
}

