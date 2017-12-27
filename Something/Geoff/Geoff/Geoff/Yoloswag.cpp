#include <iostream>

using namespace std;

// Main function
int main()
{
	// Declarations
	int david, gay = 0;

	// Prompt
	cout << "Is David gay? (Yes = 0, No = Any other key.)";
	cin >> david; // User puts their answer and presses enter

	// If-else statement
	if (david == gay)
		cout << "David is gay.";
	else
		cout << "ERROR! He always gay - Mark";

	// Ends the program
	return 0;
}