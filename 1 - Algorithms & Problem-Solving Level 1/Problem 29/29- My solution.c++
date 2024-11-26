#include <iostream>
#include <string>
using namespace std;

enum enOddOrEven {Odd = 1 , Even = 2};

int ReadNumber()
{
    int Number;
    cout << "Please enter a Number ?" << endl;
    cin >> Number;

    return Number;
}

enOddOrEven CheckOddOrEven(int Number)
{
    if (Number % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

int SumEvenNumbersFrom1ToN_UsingForLoop(int Number)
{
    cout << "\nSum Of Even Numbers Using For Statement =  ";

    int sum = 0;
    for (int counter = 1; counter <= Number; counter++)
    {
        if (CheckOddOrEven(counter) == enOddOrEven::Even)
        {
            sum = sum + counter;
        }
    }
    return sum;
}

int SumEvenNumbersFrom1ToN_UsingWhileLoop(int Number)
{
    cout << "\n\nSum Of Even Numbers Using While Statement =  ";

    int counter = 0;
    int sum = 0;
    while (counter < Number)
    {
        counter++;

        if (CheckOddOrEven(counter) == enOddOrEven::Even)
        {
            sum = sum + counter;
        }
    }
    return sum;
}

int SumEvenNumbersFrom1ToN_UsingDo_WhileLoop(int Number)
{
    cout << "\n\nSum Of Even Numbers Using Do..While Statement =  ";

    int counter = 0;
    int sum = 0;

    do 
    {
        counter++;

        if (CheckOddOrEven(counter) == enOddOrEven::Even)
        {
            sum = sum + counter;
        }

    } while (counter < Number);

    return sum;
}

int main()
{
    int Number = ReadNumber();

    cout << SumEvenNumbersFrom1ToN_UsingForLoop(Number);
    cout << SumEvenNumbersFrom1ToN_UsingWhileLoop(Number);
    cout << SumEvenNumbersFrom1ToN_UsingDo_WhileLoop(Number) << "\n";

    return 0;
}

