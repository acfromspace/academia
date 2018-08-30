/*
	Author: Andrew Christopher De Leon
	Date: 27 March 2014
	Project: Project 5
	Description: Random number guessing game!
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Declarations
	const int MIN_NUMBER = 1;
	const int MAX_NUMBER = 10;
	int number;
	int randomNum;
	char reply;

	//Prompt
	cout << "Random number guessing game!\nTry and guess the number I'm thinking of"
		<< " and you will win.\n";

	//Game processing
	do
	{
		//RNG
		srand(time(0));
		randomNum = rand() % MAX_NUMBER + MIN_NUMBER;

		cout <<"\nI'm thinking of a number between " << MIN_NUMBER << " and " << MAX_NUMBER << ".\n"
			<< "Try to guess my number: ";

		int played = 0;

		do
		{
			while (!(cin >> number) || number < MIN_NUMBER || number > MAX_NUMBER)
			{	
				cout << "\nERROR! You must enter a number between "
					<< MIN_NUMBER << " and " << MAX_NUMBER << ".\n"
					<< "Please enter a valid number: ";
				cin.clear();
				while(cin.get() != '\n');
			}

			played++;

			if (number < randomNum)
				cout << "\nToo low! Guess again: ";
			else 
				if (number > randomNum)
					cout << "\nToo high! Guess again: ";

		} while (number != randomNum);

		//Conclusion
		if (number == randomNum)
		{
			cout << "\nCongratulations, you found the number!\n"
				<< "You made " << played << " attempts at guessing the number.\n\n";
		}

		//Restart
		cout << "Press 'Y' to play again or any other key to terminate: ";
		cin >> reply;

	} while (reply == 'Y' || reply == 'y'); //Repeats game until otherwise

	cout << "\nCome play again soon!\n"
		<< endl;
	return 0;

}

/*
Random number guessing game!
Try and guess the number I'm thinking of and you will win.

I'm thinking of a number between 1 and 10.
Try to guess my number: 10

Too high! Guess again: 5

Too high! Guess again: 1

Too low! Guess again: 3

Congratulations, you found the number!
You made 4 attempts at guessing the number.

Press 'Y' to play again or any other key to terminate: y

I'm thinking of a number between 1 and 10.
Try to guess my number: Hello!

ERROR! You must enter a number between 1 and 10.
Please enter a valid number: 5

Too low! Guess again: 3

Too low! Guess again: 7

Too low! Guess again: 9

Congratulations, you found the number!
You made 4 attempts at guessing the number.

Press 'Y' to play again or any other key to terminate: No thank you!

Come play again soon!

Press any key to continue . . .
*/