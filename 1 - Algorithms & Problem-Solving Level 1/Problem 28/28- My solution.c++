#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
    int N;
    cout << "Please enter a Number ?" << endl;
    cin >> N;

    return N;
}

void PrintOddNumbersFrom1ToN_UsingForLoop(int N)
{
    cout << "Sum Of Odd Numbers Using For Statement = ";
    
    int sum = 0;

    for (int counter = 1; counter <= N; counter+=2)
    {
        sum = sum + counter;
    }
    cout << sum << endl << "\n";
}

void PrintOddNumbersFrom1ToN_UsingWhileLoop(int N)
{
    cout << "Sum Of Odd Numbers Using While Statement = ";

    int counter = 1;
    int sum = 1;
    while (counter < N-1)
    {
        counter += 2;
        sum = sum + counter;
    }
    cout << sum << endl << "\n";

}

void PrintOddNumbersFrom1ToN_UsingDoWhileLoop(int N)
{
    cout << "Sum Of Odd Numbers Using Do..While Statement = ";

    int counter = 1;
    int sum = 1;
    do
    {
        counter += 2;
        sum = sum + counter;

    } while (counter < N -1 );

    cout << sum << endl;
}

int main()
{
    int N = ReadNumber();

    PrintOddNumbersFrom1ToN_UsingForLoop(N);
    PrintOddNumbersFrom1ToN_UsingWhileLoop(N);
    PrintOddNumbersFrom1ToN_UsingDoWhileLoop(N);

    return 0;
}

