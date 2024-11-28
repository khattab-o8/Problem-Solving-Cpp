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
            cout << "  " << setw(2) << Matrix[i][j] << "       ";
        }
        cout << endl;
    }
}

short MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short Min = Matrix1[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Min > Matrix1[i][j])
            {
                Min = Matrix1[i][j];
            }
        }
    }

    return Min;
}

short MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    short Max = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Max < Matrix1[i][j])
            {
                Max = Matrix1[i][j];
            }
        }
    }

    return Max;
}

int main()
{
    int Matrix1[3][3] = { {100 , 5 , 12  }, {22 , 1 , 6  },{14 ,  3  , 9  } };

    cout << "Matrix1 : " << "\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\n\n" << "Minimum Number is : " << MinNumberInMatrix(Matrix1, 3, 3);

    cout << "\n\n" << "Maximum Number is : " << MaxNumberInMatrix(Matrix1, 3, 3) << endl;

    system("pause > 0");
}
