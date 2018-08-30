/*
Author: Andrew Christopher De Leon
Date: February 21, 2014
Assignment: Project 2
Description: Show capabilities with expressions and cout.
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	//Declarations
	int sharesOfStock = 600;
	double pricePerShare = 21.77;
	double percentCommission = 0.02;
	double stockPrice, commission, totalPaid;

	//Calculations
	stockPrice = sharesOfStock * pricePerShare;

	commission = stockPrice * percentCommission;

	totalPaid = stockPrice + commission;

	//Statements
	cout << setprecision(7) << "The amount paid for the stock alone is $" << stockPrice << ".\n"
        << "The amount for the commission is $" << commission << ".\n"
	    << "The total amount paid is $" << totalPaid << ".\n"
		<< endl;

	cout << "   *   \n"
		<< "  ***  \n"
		<< " ***** \n"
		<< "*******\n"
		<< endl;

	cout << "Data type usage:\n"
		<< "'char' uses 1 byte.\n"
		<< "'int' uses 4 bytes.\n"
		<< "'long long' uses 8 bytes.\n"
		<< "'float' uses 4 bytes.\n"
		<< "'double' uses 8 bytes.\n"
		<< endl;

	cout << "Have a good day!\n"
		<< endl;

	return 0;
}

/*
The amount paid for the stock alone is $13062.
The amount for the commission is $261.24.
The total amount paid is $13323.24.

   *
  ***
 *****
*******

Data type usage:
'char' uses 1 byte.
'int' uses 4 bytes.
'long long' uses 8 bytes.
'float' uses 4 bytes.
'double' uses 8 bytes.

Have a good day!

Press any key to continue . . .
*/