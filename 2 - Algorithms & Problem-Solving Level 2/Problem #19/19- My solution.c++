#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;

    return randnum;
}


int main()
{
    srand((unsigned) time (NULL));

    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;

    return 0;
}

