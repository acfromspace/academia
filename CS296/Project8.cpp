/*
Date: 16 May 2014
Project: 8
Description: Searching & Sorting
*/

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Prototypes.
void sortFunction (int array[], int ARRAY_SIZE);
int linearSearch(int array[], int ARRAY_SIZE, int userValue, int &counter);
int binarySearch(int array[], int ARRAY_SIZE, int userValue, int &counter);

int main()
{
	// Declarations.
	const int ARRAY_SIZE = 400;
	const int MIN_NUMBER = 1;
	const int MAX_NUMBER = 100;
	const int LIMIT = 20;
	int array[ARRAY_SIZE];
	int counter = 0;
	int random;
	int userValue;

	// Start-up.
	srand((unsigned int)time(NULL));

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		random = (rand() % MAX_NUMBER) + MIN_NUMBER;
		array[i] = random;
	}

	sortFunction(array, ARRAY_SIZE);

	cout << "400 selected numbers from values 1 ~ 100 have been selected:\n\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << setw(3) << array[i] << " ";
		if ((i + 1) % LIMIT == 0)
			cout << endl;
	}

	// Linear Function.
	cout << "\nLinear Search Algorithim Demonstration\n\n"
		<< "Please enter an integer: ";

	// Input Validation.
	while (!(cin >> userValue))
	{
		cout << "\nERROR! You must enter an integer.\n"
			<< "Please re-enter a valid value: ";
		cin.clear();
		while(cin.get() != '\n');
	}
	
	int linearResult = linearSearch(array, ARRAY_SIZE, userValue, counter);

	if (linearResult >= 0)
		cout << "\nThe number " << array[linearResult] << " was found at the element with index " 
			<< linearResult << "." << endl
			<< "It took " << counter << " comparisons before reaching the integer.\n";
		
	else
		cout << "\nThe number " << userValue << " was not found.\n";

	counter = 0;

	// Binary Function.
	cout << "\nBinary Search Algorithim Demonstration\n\n"
		<< "Please enter an integer: ";

	// Input Validation.
	while (!(cin >> userValue))
	{
		cout << "\nERROR! You must enter an integer.\n"
			<< "Please re-enter a valid value: ";
		cin.clear();
		while(cin.get() != '\n');
	}

	int binaryResult = binarySearch(array, ARRAY_SIZE, userValue, counter);

	if (binaryResult >= 0)
		cout << "\nThe number " << array[binaryResult] << " was found at the element with index " 
			<< binaryResult << "." << endl
			<< "It took " << counter << " comparisons before reaching the integer.\n\n";	
	else
		cout << "\nThe number " << userValue << " was not found.\n\n";

	return 0;
}

void sortFunction (int array[], int ARRAY_SIZE)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		for (int j = 0; j < ARRAY_SIZE - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tempNum = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tempNum;
			}
		}
	}
}

int linearSearch(int array[], int ARRAY_SIZE, int userValue, int &counter)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		counter++;
		if (userValue == array[i])
		{
			return i;
		}
	}

	return -1;
}

int binarySearch(int array[], int ARRAY_SIZE, int userValue, int &counter)
{
	int low = 0;
	int high = ARRAY_SIZE - 1; // 399

	int mid;
	
	while (low <= high)
	{
		counter++;
		mid = (low + high) / 2;

		if (userValue == array[mid])
		{
			return mid;
		}
		else 
			if (userValue > array[mid])
			{
				low = mid + 1;
			}
			else
				high = mid - 1;
	}

	return -1;

}

/*
400 selected numbers from values 1 ~ 100 have been selected:

  1   1   1   1   1   1   2   2   2   3   3   3   3   3   3   4   4   4   4   5

  5   6   6   6   6   7   7   7   7   8   8   8   9   9   9  10  10  10  10  10

 11  11  11  11  12  12  12  13  13  13  13  13  14  14  14  14  14  15  15  15

 15  15  16  16  17  17  17  17  17  17  18  18  19  19  19  19  19  19  19  20

 21  22  22  22  22  22  22  22  22  23  23  23  23  23  23  24  24  24  24  24

 24  25  25  25  25  25  25  25  26  26  27  27  27  28  28  28  29  29  30  30

 30  30  30  30  30  30  31  31  31  32  32  33  33  33  34  34  34  34  35  35

 35  35  35  35  36  36  36  36  37  37  37  38  38  38  38  38  39  39  39  39

 39  40  40  40  40  41  41  42  42  42  42  42  42  42  43  43  43  43  44  45

 45  45  45  45  45  46  46  46  46  46  46  47  47  47  47  48  48  49  49  49

 49  49  49  50  50  50  50  50  51  51  51  51  51  52  52  53  54  54  54  54

 54  54  54  55  55  55  56  56  56  56  56  56  56  56  57  57  57  57  58  58

 58  58  58  58  59  59  59  59  59  59  59  60  60  60  60  61  62  62  62  62

 63  63  63  63  64  65  65  65  67  67  67  67  68  68  68  68  69  69  69  69

 69  70  70  70  70  70  71  71  71  72  72  73  73  73  73  74  74  74  74  75

 75  75  75  76  76  77  77  77  78  78  78  78  79  79  80  80  81  82  82  82

 82  82  83  83  83  83  83  84  84  84  85  85  86  86  86  86  87  87  87  87

 87  87  88  88  88  88  88  89  89  89  89  89  89  89  90  90  90  90  90  91

 91  91  91  92  92  92  92  92  92  92  93  93  93  93  93  94  94  94  94  95

 96  96  96  96  96  97  97  97  97  98  98  98  99  99  99  99 100 100 100 100


Linear Search Algorithim Demonstration

Please enter an integer: 50

The number 50 was found at the element with index 203.
It took 204 comparisons before reaching the integer.

Binary Search Algorithim Demonstration

Please enter an integer: 999

The number 999 was not found.

Press any key to continue . . .
=================================================================
400 selected numbers from values 1 ~ 100 have been selected:

  1   1   1   1   2   2   3   3   4   4   5   5   5   5   5   5   5   6   6   7

  7   7   8   8   9  10  10  10  10  10  11  11  11  11  11  11  11  11  12  12

 12  12  12  13  13  13  13  13  13  14  14  14  15  15  15  15  15  16  16  16

 17  18  18  18  18  19  19  19  19  19  19  19  20  20  20  21  21  22  22  23

 23  23  23  24  25  25  25  26  26  26  26  26  26  27  28  28  29  29  29  29

 29  29  30  30  30  30  31  31  31  31  31  31  31  32  32  33  33  34  34  34

 34  34  34  35  35  35  35  35  35  36  36  36  36  37  37  38  39  39  39  40

 40  40  40  41  41  42  42  42  43  43  43  43  43  44  44  44  44  44  45  45

 45  46  46  46  46  47  47  47  47  47  47  47  48  48  48  48  48  48  49  49

 49  49  49  49  49  50  50  50  50  50  50  50  50  50  51  51  51  51  52  52

 53  53  53  53  53  53  53  54  54  54  54  54  54  54  55  55  56  56  56  56

 56  57  57  57  57  57  58  58  58  58  58  59  59  59  59  59  59  59  60  60

 60  61  61  61  62  62  62  62  62  62  62  62  62  63  63  64  64  64  64  64

 65  65  65  65  66  66  66  66  66  67  67  67  68  68  68  68  68  68  68  69

 69  70  70  70  70  71  71  71  72  72  72  73  73  73  73  74  74  74  75  76

 76  76  76  76  76  77  77  77  78  78  78  78  78  79  80  80  80  80  80  80

 81  81  81  82  82  82  82  82  82  83  83  83  83  84  84  84  84  84  85  85

 85  85  85  85  86  87  87  87  87  87  87  87  88  88  88  88  89  89  89  90

 90  90  90  90  90  91  91  92  92  92  93  93  93  94  94  94  94  94  95  95

 95  95  96  96  96  97  97  97  98  98  98  98  99  99  99  99  99  99  99 100


Linear Search Algorithim Demonstration

Please enter an integer: 50

The number 50 was found at the element with index 185.
It took 186 comparisons before reaching the integer.

Binary Search Algorithim Demonstration

Please enter an integer: 50

The number 50 was found at the element with index 186.
It took 5 comparisons before reaching the integer.

Press any key to continue . . .
*/