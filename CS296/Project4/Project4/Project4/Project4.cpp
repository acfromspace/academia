/*
	Author: Andrew Christopher De Leon
	Date: 21 March 2014
	Project: Project 4
	Description: Branching
*/

#include <iostream>

using namespace std;

int main()
{
	//Declarations
	const double AIR = 331.5;
	const int CO2 = 258;
	const int WATER_VAPOR = 402;
	const int METHANE = 430;
	int userInput;
	double timeInput;
	double airDistance;
	double co2Distance;
	double waterVaporDistance;
	double methaneDistance;

	//Prompt
	cout << "Finding the distance (meters) of a gas with time (seconds).\n\n"
		"1. Find distance for air\n"
		"2. Find distance for CO2\n"
		"3. Find distance for water vapor\n"
		"4. Find distance for methane\n"
		"5. Quit\n\n"
		"Please enter an input (1-5): ";
	cin >> userInput;

	//Process
	if (userInput == 1)
	{
		cout << "\nPlease input time (seconds): ";
		cin >> timeInput;
		airDistance = timeInput * AIR;
		cout << "Air has traveled a distance of " << airDistance << " meters.\n\n";
	}
	else
		if (userInput == 2)
		{
			cout << "\nPlease input time (seconds): ";
			cin >> timeInput;
			airDistance = timeInput * CO2;
			cout << "CO2 has traveled a distance of " << airDistance << " meters.\n\n";
		}
		else
			if (userInput == 3)
			{
				cout << "\nPlease input time (seconds): ";
				cin >> timeInput;
				airDistance = timeInput * WATER_VAPOR;
				cout << "Water vapor has traveled a distance of " << airDistance << " meters.\n\n";
			}
			else
				if (userInput == 4)
				{
					cout << "\nPlease input time (seconds): ";
					cin >> timeInput;
					airDistance = timeInput * METHANE;
					cout << "Methane has traveled a distance of " << airDistance << " meters.\n\n";
				}
				else
					if (userInput == 5)
						cout << "\nHave a good day!\n" << endl;
					else
						cout << "\nERROR: INVALID INPUT!\n"
							"Please restart the program.\n"
							<< endl;

	return 0;
}

/*
Finding the distance (meters) of a gas with time (seconds).

1. Find distance for air
2. Find distance for CO2
3. Find distance for water vapor
4. Find distance for methane
5. Quit

Please enter an input (1-5): 4

Please input time (seconds): 13
Methane has traveled a distance of 5590 meters.

Press any key to continue . . .
*/