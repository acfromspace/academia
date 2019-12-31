/*
Date: 22 May 2014
Project: 9
Description: Pointers

	In statistics, an Average is computed as the sum of all values divided by the count.
	Write a function that accepts an unsigned integer array, and the size of the array, 
	and returns the average of the array values as a double.

	The Mode of a set of values is the value that occurs most often or with the
	greatest frequency. Write a function that accepts the same 2 values as the Average function,
	and returns either the mode of the array, or -1 if there is no mode as an unsigned integer.

	When a set of values is sorted in ascending or descending order, its median
	is the middle value. If the set contains an even number of values, the median is the
	mean, or average, of the two middle values. Write a function that accepts the same
	2 values as the Average function, calls a sort function, and returns the Median as
	a double.  Overload your Average function to also accept 2 unsigned integers to help
	with this (Median) function.

	Demonstrate your functions by loading an allocated array of unsigned integers with a
	user-entered number of random numbers from 0 to 999, and displaying the average, mode,
	and median of the array.  Use only pointer notation (not array notation).
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Constants.
const int MAX = 999, MIN = 0, LIMIT = 15;

// Prototypes.
void ascendOrder(int *pUser, int user);
void getAverage(double &average, int totalRandom, int user);
int getMode(int *pUser, int user);
double getMedian(int *pUser, int user);

int main()
{
	// Declarations.
	int user,
		random,
		mode,
		totalRandom = 0;
	int *pUser;
	double average,
		median;

	// RNG.
	srand((unsigned int)time(NULL));

	// Prompt.
	cout << "Please enter how many random numbers to be generated: ";

	// Input Validation.
	while (!(cin >> user) || user < 0)
	{
		cout << "ERROR! You must enter a number high than 0.\n\n."
			<< "Please re-enter a valid value: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	// Pointer.
	pUser = new int[user];

	// Random numbers generated.
	for (int i = 0; i <= user; i++)
	{
		random = (rand() % MAX) + MIN;
		*(pUser + i) = random;
		totalRandom += random;
	}

	ascendOrder(pUser, user);

	// Output.
	cout << "\nThese are the numbers generated:\n\n";
	for (int *pUserAlias = pUser; pUserAlias < pUser + user; pUserAlias++)
	{
		cout << setw(3) << *pUserAlias << " ";
	}

	getAverage(average, totalRandom, user);

	cout << "\n\nThe average is: " << average << endl;

	mode = getMode(pUser, user);

	if (mode == -1)
		cout << "There is no mode.\n";
	else
		cout << "The mode is: " << mode << endl;

	median = getMedian(pUser, user);

	cout << "The median is: " << median << endl
		<< endl;

	return 0;
}

/////////////////////////////////////////////////////// Order ///
void ascendOrder(int *pUser, int user)
{
	for (int i = 0; i < user - 1; i++)
		for (int j = 0; j < user - 1; j++)
			if (*(pUser + j) > *(pUser + (j + 1)))
			{
				int tempUser = *(pUser + j);
				*(pUser + j) = *(pUser + (j + 1));
				*(pUser + (j + 1)) = tempUser;
			}
}

/////////////////////////////////////////////////////// Average ///
void getAverage(double &average, int totalRandom, int user)
{
	average = static_cast<double>(totalRandom / user);
}

/////////////////////////////////////////////////////// Mode ///
int getMode(int *pUser, int user)
{
	int mode = -1, position = 0, highest;
	int *frequency;
	frequency = new int[user];

	for (int i = 0; i < user; i++) // Frequencies are all 0.
		*(frequency + i) = 0;

	for (int i = 0; i < user; i++)
		for (int j = 1; j < user; j++)
			if (*(pUser + i) == *(pUser + j) && &*(pUser + i) != &*(pUser + j)) // Avoid counting repeats.
				*(frequency + i) += 1; // Increments frequency number.

	highest = *(frequency + 0);

	for (int i = 1; i < user; i++)
		if (*(frequency + i) > highest)
		{
			highest = *(frequency + i);
			position += i;
		}

	for (int i = 0; i < user; i++)
		if (*(frequency + i) != *(frequency + (i + 1)) && (i + 1) < user)
		{	
			mode = *(pUser + position);
			return mode; // Returns number that occurs the most.
		}

	return mode; // Returns '-1' if all same frequency.
}

/////////////////////////////////////////////////////// Median ///
double getMedian(int *pUser, int user)
{
	int mid = 0;
	double median = 0.0;

	if (user % 2 == 0)
	{
		mid = (user / 2) - 1;
		median = static_cast<double>((*(pUser + mid) + *(pUser + (mid +1))) / 2);
	}
	else
	{
		mid = (int)(user / 2);
		median = *(pUser + mid);
	}

	return median;
}

/*
Please enter how many random numbers to be generated: 200

These are the numbers generated:

  7   8   8  41  41  42  55  55  62  73  83  90  91  92  97 108 111 113 123 124
126 126 130 131 138 144 146 148 150 155 158 159 161 172 174 174 177 189 193 201
209 211 214 222 222 235 236 236 242 248 249 257 259 267 277 282 283 291 297 297
300 309 310 318 338 338 342 359 364 370 371 385 385 392 400 402 403 403 410 411
413 417 417 422 422 427 435 438 439 443 455 456 464 467 468 470 477 481 481 481
482 482 484 485 486 495 499 500 500 504 507 508 513 514 517 518 522 524 544 546
549 550 552 554 563 563 568 572 572 580 583 585 593 608 612 615 620 629 633 633
638 641 653 653 655 662 666 667 673 685 699 700 714 721 726 732 747 756 766 767
769 771 794 794 799 804 809 811 820 829 829 832 835 844 844 846 850 852 853 857
880 884 888 897 912 912 920 930 931 938 939 941 943 945 963 964 964 976 988 998


The average is: 486
The mode is: 481
The median is: 481

Press any key to continue . . .
*/