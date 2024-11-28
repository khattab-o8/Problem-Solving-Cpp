#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int ReadPositiveNumber(string Massage)
{
    int Number = 0;
    do
    {
        cout << "\n\n" << Massage;
        cin >> Number;

    } while (Number < 0);

    return Number;
}

void PrintMatrix(int Matrix[3][3], short Rows , short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << "  " << setw(2) << Matrix[i][j] << "       ";
        }
        cout << endl;
    }
}

bool IsNumberExistsInMatrix(int Matrix[3][3], short Number ,short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                system("color 2f");
                cout << "\n\n" << "Yes it is there." << "\n";
                return 1;
            }
        }
    }

    return 0;
}

int main()
{

    int Matrix[3][3] =
    { 
        {77 , 7 , 12 },
        {22 , 20 , 1 },
        {1 ,  0  , 9 } 
    };

    cout << "Matrix1 : " << "\n";
    PrintMatrix(Matrix, 3, 3);

    short Number = ReadPositiveNumber("Please Enter the Number to look for in matrix? ");

    if (IsNumberExistsInMatrix(Matrix, Number, 3, 3) )
    {
        return 1;
    }
    else
    {
        system("color 4f");
        cout << "\n\n" << "No: It's NOT Exist" << "\n";
    }


    system("pause > 0");
}
