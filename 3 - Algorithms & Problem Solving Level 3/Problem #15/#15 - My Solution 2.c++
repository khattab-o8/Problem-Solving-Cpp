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
            cout << setw(2) << " " << Matrix[i][j] << "      ";
        }
        cout << endl;
    }
}

short CountNumberInMatrix(int Number , int Matrix[3][3], short Rows, short Cols)
{
    short Counter = 0;
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                Counter++;
            }
        }
    }
    return Counter;
}

int main()
{
    system("color 1f");

    int Matrix[3][3] ={ {9 , 1 , 12}, {0 , 9 , 1 }, {0 , 9 , 9 } };

    cout << "Matrix1 : " << "\n";
    PrintMatrix(Matrix, 3, 3);

    int Number = ReadPositiveNumber("Enter the number to count in matrix? ");

    printf("\n");
    printf("Number %d count in matrix is %d ", Number, CountNumberInMatrix(Number, Matrix,3,3));


    system("pause > 0");
}
