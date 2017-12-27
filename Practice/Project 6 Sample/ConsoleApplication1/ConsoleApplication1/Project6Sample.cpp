/*
An even number is any integer that can be divided by 2 without a remainder.
A prime number is a number that is only evenly divisible by itself and 1. For example,
the number 5 is prime because it can only be evenly divided by 1 and 5. The number
6, however, is not prime because it can be divided evenly by 1, 2, 3, and 6.
Write two functions named isPrime and isEven, which take an integer as an argument and return
a Boolean. Demonstrate the function in a complete program which loops from 1 to a user entered
maximum value (validate 2 - 99):

Enter the largest value to check: 1
Error! Enter 2 through 99: 4

Value Even/Odd Prime
1 odd no
2 even no
3 odd yes
4 even no
*/

#include <iostream>
using namespace std;

//Prototypes
bool isPrime(int number);
bool isEven(int number);

int main()
{
	int number, checkedNumber, primeNumber, evenNumber;
	const int MIN = 2, MAX = 99;

	for(int number = 2; number <= 99; number++)
	for(int i = 1; i <= 99; i++)
	{
		cout << "Enter number: ";
		cin >> number;

		evenNumber = isEven(number);
		primeNumber = isPrime(number);

		if(evenNumber = true)
		cout << "Even" <<endl;

		else
		cout << "Odd" << endl;

		if(primeNumber = true)
		cout << "Yes" << endl;
		else
		cout << "No" << endl;
	}

	return 0;
}

bool isPrime(int number)
{
	if (number == 0) return false;
	if (number == 1) return false;
	if (number == 2) return true;
	if (number % 2 == 0) return false; // hide even numbers

	for (int i = 3; i < number; i += 2)
	{
		if (number % i == 0) return false;
	}

	return true;
}

bool isEven(int number)
{
  return  (number % 2 == 0);
} 