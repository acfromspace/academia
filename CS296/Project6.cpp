/*
Date: 25 April 2014
Project: 6
Description: Functions
*/

#include <iostream>
#include <string>

using namespace std;

// Prototypes.
int GetUserData(string prompt, const int MIN_NUM, const int MAX_NUM);
bool isEven(int value);
bool isPrime(int value);

int main()
{
	// Declarations.
	const int MIN_NUM = 2, MAX_NUM = 8000;
	int input, newInput;
	char reply;

	// Prompt.
	do
	{
		input = GetUserData("Please put a number: ", MIN_NUM, MAX_NUM);
	
		newInput = 6*((input)^2) + 27;

		// Conclusion.
		cout << "Value?\tEven/Odd?\tPrime?\n";
	
		// Output.
		for (int start = 1; start <= newInput; start++)
		{
			cout << start << "\t";
	
			if(isEven(start) == true)
				cout << "Even\t\t";
			else
				cout << "Odd\t\t";
	
			if(isPrime(start) == true)
				cout << "Yes!\t";
			else
				cout << "No\t";
	
			cout << endl;
		}

		// Restart.
		cout << "\n///// Press 'Y' to restart or any other key to "
			<< "terminate: ";
		cin >> reply;

	} while (reply == 'Y' || reply == 'y');

	cout << "\nHave a good day.\n"
		<< endl;
	
	return 0;
} 

// Prompt
int GetUserData(string prompt, const int MIN_NUM, const int MAX_NUM)
{
	int data;

	cout << prompt;

	while (!(cin >> data) || data < MIN_NUM || data > MAX_NUM)
	{
		cout << "ERROR! Please put a valid value from " << MIN_NUM  << " - " 
			<< MAX_NUM << ": ";
		cin.clear();
		while(cin.get() != '\n');
	}

	return data;
}

// Even/Odd Validation
bool isEven(int start)
{
	if(start % 2 != 0)
		return false;

	return true;
}

// Prime Validation
bool isPrime(int start)
{
	if (start == 1)
		return false;
	for (int i = 2; i <= start - 1; i++)
	{
		if ((start % i ) == 0)
			return false;
	}

	return true;
}

/*
Please put a number: Hello Professor!
ERROR! Please put a valid value from 2 - 99: 16
Value?  Even/Odd?       Prime?
1       Odd             No
2       Even            Yes!
3       Odd             Yes!
4       Even            No
5       Odd             Yes!
6       Even            No
7       Odd             Yes!
8       Even            No
9       Odd             No
10      Even            No
11      Odd             Yes!
12      Even            No
13      Odd             Yes!
14      Even            No
15      Odd             No
16      Even            No

///// Press 'Y' to restart or any other key to terminate: y
Please put a number: 5
Value?  Even/Odd?       Prime?
1       Odd             No
2       Even            Yes!
3       Odd             Yes!
4       Even            No
5       Odd             Yes!

///// Press 'Y' to restart or any other key to terminate: asd jhaskdbas

Have a good day.

Press any key to continue . . .
*/