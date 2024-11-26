#include <iostream>
#include <string>
using namespace std;

void Result()
{
    int Age;
    bool HasDriverLicense;

    cout << "Please Enter Your Age ? \n";
    cin >> Age;
    cout << "Do you have a driver License ? ( 1 || 0 ) \n";
    cin >> HasDriverLicense;

    cout << "\nYou\'re : ";

    if (Age >= 21 && HasDriverLicense == true)
    {
        cout << "\"Hired\"\n";

    }
    else
    {
        cout << "\"Rejected\"\n";
    }

}


int main()
{
    Result();


    return 0;
}
