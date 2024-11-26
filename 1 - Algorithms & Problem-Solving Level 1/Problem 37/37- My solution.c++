#include <iostream>
#include <string>
using namespace std;

int KeepReading()
{
    int Number = 0;
    int sum = 0;

    do
    {
        cout << "Please enter a Number ?" << endl;
        cin >> Number;
        if (Number != -99)
        {
            sum = sum + Number;
        }

    } while (Number != -99);

    return sum;

}

void PrintResult(int sum)
{
    cout << "\n" << "Result = " << sum << endl;
}

int main()
{
    PrintResult(KeepReading());

    return 0;
}

