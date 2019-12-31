#include <iostream>
#include <string>
#include <regex>

using namespace std;

// Prototypes.
string GetNumberAsString(string prompt);
int AddLeftPadding(const string &LongNum, string &ShortNum);
void RemoveLeftPadding(string &Num);
void AddBCD(const string num1, const string num2, string &answer, bool &carry);
void SubtractBCD(const string num1, const string num2, string &answer, bool &carry);

int main()
{
	// Declarations.
	string num1, num2, answer = "", underline = "";
	int length, input, digit = 0;
	bool carry = false;

	num1 = GetNumberAsString("Num1: ");
	num2 = GetNumberAsString("Num2: ");

	// Left-pad.
	if (num1.length() > num2.length())
		length = AddLeftPadding(num1, num2);
	else
		if (num2.length() > num1.length())
			length = AddLeftPadding(num2, num1);
		else
			length = num1.length() - 1;
	
	cout << "What would you like to do with these numbers?\n\n"
		<< "1. Add" << endl
		<< "2. Subtract" << endl
		<< "3. Multiply" << endl
		<< "4. Divide" << endl < endl;
	cin >> input;

	switch (input)
	{
		case 1:
			AddBCD(num1, num2, answer, carry);
			break;
		case 2:
			SubtractBCD(num1, num2, answer, carry);
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "\n\nHave a good day.";
			break;
	}

	// Display the operands and answer.
	RemoveLeftPadding(num1);
	RemoveLeftPadding(num2);
	underline.insert(0, length + 2, '-');
	cout << "\n " << num1 << endl
		<< "+" << num2 << endl
		<< underline << endl
		<< (carry?"":" ") << answer << endl << endl;

	return 0;
}

// Get user-entered number, call with prompt, returns string containing number.
string GetNumberAsString(string prompt)
{
	string Num;

	cout << prompt;
	cin >> Num;
	while(regex_search(Num.begin(), Num.end(), regex("[^0-9]")))
	{
		cout << "Enter digits only: ";
		cin >> Num;
	}

	return Num;
}

// Left Pad the shorter of the two numbers, send longer &string, then shorter &string, returns an index.
int AddLeftPadding(const string &LongNum, string &ShortNum)
{
	int longLength;

	longLength = LongNum.length() - 1;
	ShortNum.insert(0, LongNum.length() - ShortNum.length(), '0');

	return longLength;
}

void RemoveLeftPadding(string &Num)
{
	int ix = 0;

	while (ix <= Num.length() - 1 && Num[ix] == '0')
		Num[ix++] = ' ';
}

void AddBCD(const string num1, const string num2, string &answer, bool &carry)
{
	int digit;
	for (int ix = num2.length() - 1; ix >= 0; ix--)
	{
		digit = num1[ix] + num2[ix] + (carry?1:0) - '0' - '0';
		answer.insert(0, 1, static_cast<char>(digit % 10 + '0'));
		carry = digit>9?true:false;
	}
	if (carry)
		answer.insert(0, 1, '1');
}

void SubtractBCD(const string num1, const string num2, string &answer, bool &carry)
{
	int digit;
	for (int ix = num2.length() - 1; ix >= 0; ix--)
	{
		digit = num1[ix] - num2[ix] + (carry?1:0) - '0' - '0';
		answer.insert(0, 1, static_cast<char>(digit % 10 + '0'));
		carry = digit>9?true:false;
	}
	if (carry)
		answer.insert(0, 1, '1');
}