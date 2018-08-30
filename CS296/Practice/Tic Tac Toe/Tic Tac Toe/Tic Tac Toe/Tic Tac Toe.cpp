#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 3;

char a[SIZE][SIZE] = {
{'*','*','*'},
{'*','*','*'},
{'*','*','*'}
};

char b = '0';

void draw();
bool getinputP1();
bool getinputP2();
bool checkwinP1();
bool checkwinP2();

int main()
{
	draw();
	cout << "Player one make your move" << endl;
	getinputP1();
	draw();
	cout << "Player two make your move" << endl;
	getinputP2();
	draw();

	for (;;)
	{
		cout << "Player one make your move" << endl;
		getinputP1();

		if(checkwinP1() == 1)
		{
			draw();
			cout << "Player one, you win!" << endl;
			break;
		}

		draw();
		cout << "Player two make your move" << endl;
		getinputP2();

		if(checkwinP2() == 1)
		{
			draw();
			cout << "Player two, you win!" << endl;
			break;
		}
		else 
		{
			draw();
			cout << "It's a tie" << endl;
			break;
		}
	}

	return 0;
}


void draw()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(5) << a[j];
		}
		cout << endl;
	}
}

bool getinputP1()
{
	cout << "Enter your move" << endl;
	cin >> b;
	switch(b)
	{
		case '1' : a[0][0] = 'X'; break;
		case '2' : a[0][1] = 'X'; break;
		case '3' : a[0][2] = 'X'; break;
		case '4' : a[1][0] = 'X'; break;
		case '5' : a[1][1] = 'X'; break;
		case '6' : a[1][2] = 'X'; break;
		case '7' : a[2][0] = 'X'; break;
		case '8' : a[2][1] = 'X'; break;
		case '9' : a[2][2] = 'X'; break;
		default: cout << "Hey!! You have to play by the rules!" << endl;
	}
	return 0;
}

bool getinputP2()
{
	cout << "Enter your move" << endl;
	cin >> b;
	switch(b)
	{
		case '1' : a[0][0] = 'O'; break;
		case '2' : a[0][1] = 'O'; break;
		case '3' : a[0][2] = 'O'; break;
		case '4' : a[1][0] = 'O'; break;
		case '5' : a[1][1] = 'O'; break;
		case '6' : a[1][2] = 'O'; break;
		case '7' : a[2][0] = 'O'; break;
		case '8' : a[2][1] = 'O'; break;
		case '9' : a[2][2] = 'O'; break;
		default: cout << "Hey!! You have to play by the rules!" << endl;
	}
	return 0;
}

bool checkwinP1()
{
if(a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X') return 1;
if(a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X') return 1;
if(a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X') return 1;
if(a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X') return 1;
if(a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X') return 1;
if(a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X') return 1;
if(a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X') return 1;
if(a[2][0] == 'X' && a[1][1] == 'X' && a[0][2] == 'X') return 1;
}

bool checkwinP2()
{
if(a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O') return 1;
if(a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O') return 1;
if(a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O') return 1;
if(a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O') return 1;
if(a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O') return 1;
if(a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O') return 1;
if(a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O') return 1;
if(a[2][0] == 'O' && a[1][1] == 'O' && a[0][2] == 'O') return 1;
}