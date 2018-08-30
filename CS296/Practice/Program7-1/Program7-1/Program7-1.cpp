// Inputting and Outputting Array Contents

#include <iostream>
using namespace std;

int main()
{
	// Declarations
	const int NUM_EMPLOYEES = 6;
	int hours [NUM_EMPLOYEES];

	// Get hours worked by each employee.
	cout << "Enter the hours worked by "
		<< NUM_EMPLOYEES << " employees: \n";
	cin >> hours[0];
	cin >> hours[1];
	cin >> hours[2];
	cin >> hours[3];
	cin >> hours[4];
	cin >> hours[5];

	// Display the values in the array.
	cout << "The hours you enter are: "
		<< hours[0] << ", "
		<< hours[1] << ", "
		<< hours[2] << ", "
		<< hours[3] << ", "
		<< hours[4] << ", "
		<< hours[5]
		<< endl << endl ;
	return 0;
}