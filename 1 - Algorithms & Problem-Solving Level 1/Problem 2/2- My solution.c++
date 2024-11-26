#include <iostream>
#include <string>
using namespace std;

int main()
{
    string Name;

    cout << "Please enter your Name ?\n";
    getline(cin, Name);
    cout << endl << "Your Name is : " << Name << "\n";

    return 0;
}
