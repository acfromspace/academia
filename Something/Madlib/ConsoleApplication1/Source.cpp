#include <iostream>
#include <string>
using namespace std;

int main()
{

   string userName;
   string userCity;
   int userAge;
   string userCollege;
   string userProfession;
   string userAnimal;
   string userPetName;

    cout << "Name: ";
    getline(cin,userName);

    cout << "City: ";
    getline(cin,userCity);

    cout << "Age: ";
    cin >> userAge;

    cout << "College: ";
    cin.ignore(100,'\n');
    getline(cin,userCollege);

    cout << "Profession: ";
    getline(cin,userProfession);

    cout << "Animal: ";
    getline(cin,userAnimal);

    cout << "Pet Name: ";
    getline(cin,userPetName);
    
    cout << "\n\nThere once was a person named " << userName << " who lived in " << userCity << ".\n";
      cout << "At the age of " << userAge;
    cout << ", " << userName << " went to college at " << userCollege << ".\n ";
    cout << userName << " graduated and went to work as a " << userProfession << ".\n Then, ";
    cout << userName << " adopted a(n) " << userAnimal << " named " << userPetName << ".\n";
    cout << "They both lived happily ever after!";

	return 0;
}