#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReplaceWordInString(string S, string WordToReplace, string ReplaceTo)
{
    short Pos = 0;
    while ((Pos = S.find(WordToReplace)) != std::string::npos )
    {
        S.replace(Pos, WordToReplace.length(), ReplaceTo);

        Pos = S.find(WordToReplace);
    }

    return S;
}

int main()
{
    string S = "Welcome to Jordan , Jordan is a nice country";

    cout << "\nOriginal String \n" << S << endl;

    cout << "\nString After replace: \n";
    cout << ReplaceWordInString(S, "Jordan", "Egypt");



    system("pause > 0");
    return 0;
}