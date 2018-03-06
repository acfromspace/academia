Monolithic: Application infrastructure is presented/written as a single application that does everything.
    Pro: You don''t have to rely on 3rd party libaries/applications.
         You can "touch" everything in the application.
    Con: You can "touch" everything.
         Hard to maintain.

Micro: All the parts are seperated by abstraction concept.
    Pro: KISS (Each part is easy to maintain)
    Con: Restricted by concept. Not all concepts are encapsulated well.

Cohesion: How well different parts of abstractions work together. Cohesion is good.

Coupling: How much different abstractions rely on specific implementations in other abstractions. Low coupling is good.

Say for example: Program 'A' can do something while Program 'B' can do something else based on 'A'.

#include <stdio.h>

// gcc ******.c -o partA
// ./partA | ./partA

int main()
{
    int x;
    scanf(" %d ", &x);
    printf("%d\n", x*2);
}

C++ **************************************************************************

#include <iostream>

// g++ ***.cpp -o ***
// ./***
// *** = file name


int main()
{
    int x;
    std::cin >> x;
    std::cout << x + 2 << std::endl;
}

// ./partB | ./partA
// Try it

#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    cin >> x;
    cout << x + 3 << endl;
}