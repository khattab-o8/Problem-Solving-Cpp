#include <iostream>
#include <string>
using namespace std;

void Output()
{
    int Number;
    cout << "Please enter A Number ?\n";
    cin >> Number;

    cout << "\nThe Number you entered is : ";

    if (Number % 2 == 0)
    {
        cout << "\"Even Number\"\n";
    }
    else 
    {
        cout << "\"Odd Number\"\n";
    }
}


int main()
{
    Output();
    return 0;
}
