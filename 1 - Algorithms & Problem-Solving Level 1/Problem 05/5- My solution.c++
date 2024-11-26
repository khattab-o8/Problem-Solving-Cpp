#include <iostream>
#include <string>
using namespace std;

struct InPut
{
    short int Age;
    bool HasDriverLicense;
    bool HasRecommendation;

};

void ReadData(InPut& Info)
{

    cout << "Please Enter your Age ? \n";
    cin >> Info.Age;

    cout << "Do you have a driver License?, choose (1 or 0)\n";
    cin >> Info.HasDriverLicense;

    cout << "Do you have a Recommendation ?, choose (1 or 0)\n";
    cin >> Info.HasRecommendation;
}

void OutPut(InPut Info)
{
    cout << "\nYou\'re : ";

    if ((Info.HasRecommendation == true) || (Info.Age > 21 && Info.HasDriverLicense == true))
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
    InPut Info;
    
    ReadData(Info);
    OutPut(Info);


    return 0;
}