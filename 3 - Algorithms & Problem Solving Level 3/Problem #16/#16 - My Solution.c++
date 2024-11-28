#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows , short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(2) << " " << Matrix[i][j] << "      ";
        }
        cout << endl;
    }
}

short CountZeroNumbersInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short Zcounter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == 0 )
            {
                Zcounter++;
            }
        }
    }
    return Zcounter;
}

short CountIntegerNumbersInMatrix(int Matrix[3][3], short Rows, short Cols)
{
    short Intcounter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] != 0 )
            {
                Intcounter++;
            }
        }
    }
    return Intcounter;
}

bool IsSparceMatrix(int Matrix[3][3], short Rows, short Cols)
{
    return CountZeroNumbersInMatrix(Matrix, 3, 3) > CountIntegerNumbersInMatrix(Matrix, 3, 3);
}

int main()
{

    int Matrix[3][3] =
    { 
        {0 , 0 , 12},
        {0 , 0 , 1 },
        {0 , 0 , 9 } 
    };

    cout << "Matrix1 : " << "\n";
    PrintMatrix(Matrix, 3, 3);

    if (IsSparceMatrix(Matrix, 3, 3))
    {
        system("color 2f");
        cout << "\n\n" << "Yes: It is Sparse" << "\n";
    }
    else
    {
        system("color 4f");
        cout << "\n\n" << "No: It's NOT Sparse" << "\n";
    }


    system("pause > 0");
}
