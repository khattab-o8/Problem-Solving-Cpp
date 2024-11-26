#include <iostream>
#include <string>
using namespace std;

struct STRPiggyBank
{
    float Pennies, Nickels, Dimes, Quarters, Dollars;
};

STRPiggyBank ReadMoneyValues()
{
    STRPiggyBank input;

    cout << "Please enter Pennies ? " << endl;
    cin >> input.Pennies;

    cout << "Please enter Nickels ? " << endl;
    cin >> input.Nickels;

    cout << "Please enter Dimes ? " << endl;
    cin >> input.Dimes;

    cout << "Please enter Quarters ? " << endl;
    cin >> input.Quarters;

    cout << "Please enter Dollars ? " << endl;
    cin >> input.Dollars;

    return input;
}

float CalculateTotalPennies(STRPiggyBank input)
{
    float TotalPennies;

    TotalPennies = input.Pennies + (input.Nickels * 5) + (input.Dimes * 10) + (input.Quarters * 25) + (input.Dollars * 100);
    
    return TotalPennies;

}

float CalculateTotalDollars(STRPiggyBank input)
{
    float TotalDollars;

    TotalDollars = CalculateTotalPennies(input) / 100;

    return TotalDollars;
}

void Printresult(float TotalPennies, float TotalDollars)
{
    cout << "\n" << "Total Pennies = " << TotalPennies << " Pennies " << endl;
    cout << "\n" << "Total Dollars = " << TotalDollars << " Dollars " << endl;
}

int main()
{
    STRPiggyBank input = ReadMoneyValues();

    Printresult(CalculateTotalPennies(input), CalculateTotalDollars(input));

    return 0;
}

