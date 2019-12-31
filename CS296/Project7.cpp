/*
Date: 7 May 2014
Project: 7
Description: Multi-dimensional Arrays
	1) getTotal
	2) getAverage
	3) getRowTotal
	4) getColumnTotal
	5) getHighestInRow
	6) getLowestInRow
	7) getHighestInColumn
	8) getLowestInColumn
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Constants.
const int PLAYERS = 5,
		  GAMES = 3,
		  MAX_SCORE = 30;

// Prototypes.
int totalScore(int score[][GAMES], int PLAYERS, int GAMES);
double averageScore(int score[][GAMES], int PLAYERS, int GAMES, int total);
int totalPlayerScore(int score[][GAMES], int GAMES, int &playerChoice);
int totalGameScore(int score[][GAMES], int PLAYERS, int &gameChoice);
int highestPlayerScore(int score[][GAMES], int GAMES, int &playerChoice);
int lowestPlayerScore(int score[][GAMES], int GAMES, int MAX_SCORE, int &playerChoice);
int highestGameScore(int score[][GAMES], int PLAYERS, int &playerChoice);
int lowestgameScore(int score[][GAMES], int PLAYERS, int MAX_SCORE, int &gameChoice);

int main()
{
	// Declarations.
	int score[PLAYERS][GAMES] = { 
		{8,10,10},
		{1,2,3},
		{4,5,6},
		{3,6,9},
		{8,6,4}
		};
	int inputMenu;
	int playerChoice;
	int gameChoice;
	int totalPlayer;
	int totalGame;
	int totalAll;
	int highestPlayer;
	int lowestPlayer;
	int highestGame;
	int lowestGame;
	char restart;
	double average;

	// Program.
	do
	{
		// Prompt.
		cout << "Player scores and games\n\n"
			<< "1. Total scores\n"
			<< "2. Average score per game\n"
			<< "3. Total scores for a certain player\n"
			<< "4. Total scores for a certain game\n"
			<< "5. Highest score for a certain player\n"
			<< "6. Lowest score for a certain player\n"
			<< "7. Highest score for a certain game\n"
			<< "8. Lowest score for a certain game\n"
			<< "9. Quit\n\n"
			<< "Please put an option: ";
		
		// Input Validation.
		while (!(cin >> inputMenu))
		{
			cout << "\nERROR! Please put in a valid value from numbers 1 through 9: ";
			cin.clear();
			while(cin.get() != '\n');
		}
	
		switch (inputMenu)
		{
			// Total.
			case 1:
				totalAll = totalScore(score, PLAYERS, GAMES);
				cout << "The total score for all games was " << totalAll << ".\n\n";
				break;
			// Average.
			case 2:
				totalAll = totalScore(score, PLAYERS, GAMES);
				average = averageScore(score, PLAYERS, GAMES, totalAll);
				cout << "The average score for all games was " << setprecision(3) << average << ".\n\n";
				break;
			// Row Total.
			case 3:
				cout << "Please enter player number (1 ~ " << PLAYERS << "): ";
				while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > PLAYERS)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << PLAYERS << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				totalPlayer = totalPlayerScore(score, GAMES, playerChoice);
				cout << "The total score for Player " << playerChoice << " is " << totalPlayer << ".\n\n";
				break;
			// Column Total.
			case 4:
				cout << "Please enter game number (1 ~ " << GAMES << "): ";
				while (!(cin >> gameChoice) || gameChoice < 1 || gameChoice > GAMES)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << GAMES << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				totalGame = totalGameScore(score, PLAYERS, gameChoice);
				cout << "The total score for Game " << gameChoice << " is " << totalGame << ".\n\n";
				break;
			// HighestInRow.
			case 5:
				cout << "Please enter player number (1 ~ " << PLAYERS << "): ";
				while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > PLAYERS)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << PLAYERS << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				highestPlayer = highestPlayerScore(score, GAMES, playerChoice);
				cout << "The highest score for Player " << playerChoice << " is " << highestPlayer << ".\n\n";
				break;
			// LowestInRow.
			case 6:
				cout << "Please enter player number (1 ~ " << PLAYERS << "): ";
				while (!(cin >> playerChoice) || playerChoice < 1 || playerChoice > PLAYERS)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << PLAYERS << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				lowestPlayer = lowestPlayerScore(score, GAMES, MAX_SCORE, playerChoice);
				cout << "The lowest score for Player " << playerChoice << " is " << lowestPlayer << ".\n\n";
				break;
			// HighestInCol.
			case 7:
				cout << "Please enter game number (1 ~ " << GAMES << "): ";
				while (!(cin >> gameChoice) || gameChoice < 1 || gameChoice > GAMES)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << GAMES << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				highestGame = highestGameScore(score, PLAYERS, gameChoice);
				cout << "The highest score for Game " << gameChoice << " is " << highestGame << ".\n\n";
				break;
			// LowestInCol.
			case 8:
				cout << "Please enter game number (1 ~ " << GAMES << "): ";
				while (!(cin >> gameChoice) || gameChoice < 1 || gameChoice > GAMES)
				{
					cout << "\nERROR! Please put in a valid value from numbers 1 through " << GAMES << ": ";
					cin.clear();
					while(cin.get() != '\n');
				}
				lowestGame = lowestgameScore(score, PLAYERS, MAX_SCORE, gameChoice);
				cout << "The lowest score for Game " << gameChoice << " is " << lowestGame << ".\n\n";
				break;
			// Quit.
			case 9:
				cout << "You chose to quit the selection.\n\n";
				break;
			// Error statement.
			default:
				cout << "ERROR! Bringing up restart statement.\n\n";
				break;
		} 

		cout << "Press 'Y' to restart the program or any other key to terminate: ";
		cin >> restart;
		cout << endl;

	} while (restart == 'Y' || restart == 'y');

	cout << "Have a good day.\n" << endl;

	return 0;
}

int totalScore(int score[][GAMES], int PLAYERS, int GAMES)
{
	int totalAll = 0;

	for (int row = 0; row < PLAYERS; row++)
		for (int col = 0; col < GAMES; col++)
		{
			totalAll += score[row][col];
		}

	return totalAll;
}
double averageScore(int score[][GAMES], int PLAYERS, int GAMES, int totalAll)
{
	double average;
	average = static_cast<double> (totalAll) / GAMES;
	return average;
}

int totalPlayerScore(int score[][GAMES], int GAMES, int &playerChoice)
{
	int totalPlayer = 0;

	for (int col = 0; col < GAMES; col++)
	{
		totalPlayer += score[playerChoice - 1][col];
	}

	return totalPlayer;
}

int totalGameScore(int score[][GAMES], int PLAYERS, int &gameChoice)
{
	int totalGame = 0;

	for (int row = 0; row < PLAYERS; row++)
	{
		totalGame += score[row][gameChoice - 1];
	}

	return totalGame;
}

int highestPlayerScore(int score[][GAMES], int GAMES, int &playerChoice)
{
	int highestPlayer = 0;
	int highScore;

	for (int col = 0; col < GAMES; col++)
	{
		highScore = score[playerChoice - 1][col];
		if (highScore > highestPlayer)
			highestPlayer = highScore;
	}

	return highestPlayer;
}

int lowestPlayerScore(int score[][GAMES], int GAMES, int MAX_SCORE, int &playerChoice)
{
	int lowestPlayer = MAX_SCORE;
	int lowScore;

	for (int col = 0; col < GAMES; col++)
	{
		lowScore = score[playerChoice - 1][col];
		if (lowScore < lowestPlayer)
			lowestPlayer = lowScore;
	}

	return lowestPlayer;
}

int highestGameScore(int score[][GAMES], int PLAYERS, int &gameChoice)
{
	int highestGame = 0;
	int highScore;

	for (int row = 0; row < PLAYERS; row++)
	{
		highScore = score[row][gameChoice - 1];
		if (highScore > highestGame)
			highestGame = highScore;
	}

	return highestGame;
}

int lowestgameScore(int score[][GAMES], int PLAYERS, int MAX_SCORE, int &gameChoice)
{
	int lowestGame = MAX_SCORE;
	int lowScore;

	for (int row = 0; row < PLAYERS; row++)
	{
		lowScore = score[row][gameChoice - 1];
		if (lowScore < lowestGame)
			lowestGame = lowScore;
	}

	return lowestGame;
}

/*
Player scores and games

1. Total scores
2. Average score per game
3. Total scores for a certain player
4. Total scores for a certain game
5. Highest score for a certain player
6. Lowest score for a certain player
7. Highest score for a certain game
8. Lowest score for a certain game
9. Quit

Please put an option: NULL

ERROR! Please put in a valid value from numbers 1 through 9: 1
The total score for all games was 85.

Press 'Y' to restart the program or any other key to terminate: y

Player scores and games

1. Total scores
2. Average score per game
3. Total scores for a certain player
4. Total scores for a certain game
5. Highest score for a certain player
6. Lowest score for a certain player
7. Highest score for a certain game
8. Lowest score for a certain game
9. Quit

Please put an option: 5
Please enter player number (1 ~ 5): 3
The highest score for Player 3 is 6.

Press 'Y' to restart the program or any other key to terminate: y

Player scores and games

1. Total scores
2. Average score per game
3. Total scores for a certain player
4. Total scores for a certain game
5. Highest score for a certain player
6. Lowest score for a certain player
7. Highest score for a certain game
8. Lowest score for a certain game
9. Quit

Please put an option: 9
You chose to quit the selection.

Press 'Y' to restart the program or any other key to terminate: No

Have a good day.

Press any key to continue . . .
*/