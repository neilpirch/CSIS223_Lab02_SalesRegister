// Lab02-SalesRegister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const double MO_SALES_TAX_RATE = 0.04316;
const double KS_SALES_TAX_RATE = 0.068;

double	saleAmountCalc(int, double);						// qty, price
double	salesTaxCalc(double, string);						// saleAmt, stateCode
void	displaySaleData(string, double, double, string);	// custName, saleAmt, salesTax, stateCode

int main()
{
	string	custName;
	string	stateCode;
	int		qty;
	double	price;
	char	dollarSign = '$';
	double	saleAmt;
	double	salesTax;

	double	salesTotal = 0.00;
	double	taxTotal = 0.00;
	double	taxMO = 0.00;
	double	taxKS = 0.00;
	
	string	fileName = "salesRegister.txt";

	ifstream	salesFile;

	salesFile.open(fileName);

	if (!salesFile)
	{
		cout << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -1;
	}

	salesFile >> custName;

	while (!salesFile.eof())
	{
		salesFile >> stateCode >> qty >> price;

		// Process data		

		saleAmt = saleAmountCalc(qty, price);

		salesTax = salesTaxCalc(saleAmt, stateCode);

		displaySaleData(custName, saleAmt, salesTax, stateCode);

		salesTotal += saleAmt;
		taxTotal += salesTax;
		if (stateCode == "MO")
		{
			taxMO += salesTax;
		}
		else
		{
			taxKS += salesTax;
		}
		// Priming read
		salesFile >> custName;

	}

	salesFile.close();

	cout << endl << setw(23) << "$" << setw(9) << right << salesTotal << "  $" << setw(8) << right << taxTotal << "  Total" << endl;

	cout << endl << setw(35) << "Sales Tax:   " << setw(8) << right << taxMO << "  MO" << endl;
	cout << endl << setw(35) << "             " << setw(8) << right << taxKS << "  KS" << endl;


	/*cout << endl << "                         $" << setw(9) << right << grandTotal << endl;

	cout << endl << setw(8) << cnt << "  records processed" << endl << endl;
*/
	


	system("pause");
	return 0;
}


double	saleAmountCalc(int a, double b)
{
	return a * b;
}

double	salesTaxCalc(double a, string b)
{
	if (b == "MO")
	{
		return a * MO_SALES_TAX_RATE;
	}
	else 
	{
		return a * KS_SALES_TAX_RATE;
	}
}

void	displaySaleData(string a, double b, double c, string d)
{
	static char dollarSign = '$';

	cout << left << setw(20) << a << "  " << dollarSign << setw(9) << right << fixed << setprecision(2) << b;
	cout << "  " << dollarSign << setw(8) << c << "  " << d << endl;

	dollarSign = ' ';

}