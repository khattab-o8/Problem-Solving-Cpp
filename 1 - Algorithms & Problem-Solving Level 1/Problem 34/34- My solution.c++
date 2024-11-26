#include <iostream>
#include <string>
using namespace std;

float ReadSalesInRange(float From,float To)
{
    float TotalSales;

	do
	{
		cout << "Please enter Tatal Sales from 0 to 1 Million ? " << endl;
		cin >> TotalSales;

	} while (TotalSales < From || TotalSales > To);

	return TotalSales;
}

float CalculateCommission(float TotalSales)
{
	if (TotalSales >= 1000000)
		return .01 * TotalSales;
	else if (TotalSales >= 500000)
		return .02 * TotalSales;
	else if (TotalSales >= 100000)
		return .03 * TotalSales;
	else if (TotalSales >= 50000)
		return .05 * TotalSales;
	else
		return 0 * TotalSales;
}


int main()
{
	
	cout << "\n" << "Commission = " << CalculateCommission(ReadSalesInRange(0, 1000000)) << endl;

    return 0;
}

