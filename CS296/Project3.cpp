/*
Date: 5 March 2014
Project: 3
Description: Expressions and Interactivity.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	// Declarations.
	string months;
	const double TAXRATE_COUNTY = 0.02;
	const double TAXRATE_STATE = 0.0725;
	double totalCollected, sales, countySalesTax, stateSalesTax, totalSalesTax;
	int salesYear;
	
	// Input Statements.
	cout << setprecision(2) << fixed;
	cout << "Enter total collected ($): ";
	cin >> totalCollected;
	cin.ignore();
	cout << "Enter sales months: ";
	getline(cin,months);
	cout << "Enter sales year: ";
	cin >> salesYear;
	
	// Calculations.
	sales = (1 - (TAXRATE_COUNTY + TAXRATE_STATE)) * totalCollected;
	countySalesTax = totalCollected * TAXRATE_COUNTY;
	stateSalesTax = totalCollected * TAXRATE_STATE;
	totalSalesTax = countySalesTax + stateSalesTax;

	// Output Statements.
	cout << "\nMonths: " << months << " " << salesYear
		<< "\n----------------------------------------" << endl
		<< "Totaled Collected:" << setw(5) << "$" << totalCollected << endl
		<< "Sales:"<< setw(18) << "$" << sales << endl
		<< "County Sales Tax:" << setw(8) << "$" << countySalesTax << endl
		<< "State Sales Tax:" << setw(9) << "$" << stateSalesTax << endl
		<< "Total Sales Tax:" << setw(9) << "$" << totalSalesTax << endl
		<< endl;

	return 0;
}

/*
Enter total collected ($): 1000
Enter sales months: Jan, Feb, and Mar
Enter sales year: 2014

Months: Jan, Feb, and Mar 2014
----------------------------------------
Totaled Collected:    $1000.00
Sales:                 $907.50
County Sales Tax:       $20.00
State Sales Tax:        $72.50
Total Sales Tax:        $92.50

Press any key to continue . . .
*/