#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S = " ";
    cout << "\nPlease Enter Your String ? \n";
    getline(cin, S);

    return S;
}

vector <string> SplitString(string S, string Delim = " ")
{
    vector <string> vString;

    short Pos = 0;  string sWord = " ";

    while ((Pos = S.find(Delim)) != std::string::npos)
    {
        sWord = S.substr(0, Pos);

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S.erase(0, Pos + Delim.length());
    }
    if (S != "")
    {
        vString.push_back(S);
    }

    return vString;
}

string JoinStringInReversedOrder(string S, string Delim = " ")
{
    vector <string> vString;
    vString = SplitString(S);

    string Line = "";

    reverse(vString.begin(), vString.end());

    //ranged loop
    for (string& word : vString)
    {
        Line += word + Delim;
    }
 
    return Line.substr(0, Line.length() - Delim.length());
}

int main()
{
    string S = ReadString();

    cout << "\n\nString after reversing words: \n";
    cout << JoinStringInReversedOrder(S);


    system("pause > 0");
    return 0;
}