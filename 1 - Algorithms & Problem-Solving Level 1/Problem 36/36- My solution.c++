#include <iostream>
#include <string>
using namespace std;

struct STROperation
{
    int Number1, Number2;
    char OperationType;
};

STROperation ReadOperationData()
{
    STROperation input;

    cout << "Please enter Number 1 ?" << endl;
    cin >> input.Number1;

    cout << "Please enter Number 2 ?" << endl;
    cin >> input.Number2;

    cout << "Please enter Operation Type ?" << endl;
    cin >> input.OperationType;

    return input;
}

float PerformCalculation(STROperation input)
{

    if (input.OperationType == '+')
        return input.Number1 + input.Number2;
    else if (input.OperationType == '-')
        return input.Number1 - input.Number2;
    else if (input.OperationType == '*')
        return input.Number1 * input.Number2;
    else if (input.OperationType == '/')
        return input.Number1 / input.Number2;
   
}

int main()
{
    STROperation input = ReadOperationData();
    
    cout << "\n" << " OutPut = " << PerformCalculation(input) << endl;


    return 0;
}

