#include <iostream>

using namespace std;

// Global.
	const int MSG_MAX = 100; // Whatever number you want.
	const int ASCII_MAX = 94; // ASCII Chart from (Dec) 32 to 126, 126 - 32 = 94.

// Prototypes.
	void function(char msg[], int ASCIIvalues[]);

int main()
{
	char msg[MSG_MAX] = {0};
	int ASCIIvalues[ASCII_MAX] = {0};

	cin.getline(msg, MSG_MAX);

	function(msg, ASCIIvalues);

	return 0;
}

void function(char msg[], int ASCIIvalues[])
{
	for (int i = 0; i < ASCII_MAX; i++) // Goes through printable ASCII values.
	{
		for (int j = 0; j < MSG_MAX; j++) // Goes through message.
		{
			if (msg[j] == static_cast<char>(i + '!'))
				ASCIIvalues[i]++;
		}
	}

	for (int i = 0; i < ASCII_MAX; i++)
	{
			if (ASCIIvalues[i] == 1)
			{
				cout << static_cast<char>(i + '!') << " is the first character that doesn't repeat itself." << endl;
				break;
			}
			else
				continue;
	}
}