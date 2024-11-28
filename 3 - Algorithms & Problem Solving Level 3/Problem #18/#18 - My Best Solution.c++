#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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

void TransferMatrix2ElementsToVector(vector <int>& vNumber, int Matrix2[3][3], short Rows, short Cols)
{
    short Number = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix2[i][j];
            vNumber.push_back(Number);
        }
    }
}

void PrintIntersectedNumbersBetweenVectorAndMatrix1(vector <int>& vNumber, int Matrix1[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // ranged loop for vector
            for (int & Number : vNumber)
            {
                if (Number == Matrix1[i][j])
                {
                    cout << "  " << setw(2) << Number << "   ";

                }
            }
        }
    }
}

int main()
{
    vector <int> vNumber;

    int Matrix1[3][3] = {{77 , 5 , 12 },{22 , 20 , 1  },{1 ,  0  , 9  }},
        Matrix2[3][3] = {{5  , 80 , 90 },{22 , 77 , 1  },{10 , 8  , 33 }};

    cout << "Matrix1 : " << "\n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\n\n" << "Matrix2 : " << "\n";
    PrintMatrix(Matrix2, 3, 3);

    TransferMatrix2ElementsToVector(vNumber, Matrix2, 3, 3);

    cout << "\n\n" << "Intersected Numbers are: " << "\n\n";
    PrintIntersectedNumbersBetweenVectorAndMatrix1(vNumber, Matrix1, 3,3);

    system("pause > 0");
}
