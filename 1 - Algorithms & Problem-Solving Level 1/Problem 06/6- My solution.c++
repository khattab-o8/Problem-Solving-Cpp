#include <iostream>
#include <string>
using namespace std;

struct Name
{
    string FirstName, LastName;
};

Name FullName(Name Input)
{
    cout << "Please enter Your First Name?\n";
    cin >> Input.FirstName;
    cout << "Please enter your Last Name?\n";
    cin >> Input.LastName;

    return Input;
}

void PrintFullName(Name Input)
{
    cout << "\nYour Full Name is : " << Input.FirstName + " " + Input.LastName << "\n";

}


int main()
{
    Name Input;
    PrintFullName(FullName(Input));

    return 0;
}
