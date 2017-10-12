Abstractions
    Generalized concepts, that are usable without breaking themselves.
Programming
    Using abstractions to solve problems.
OOPovel (new) types.
    The breakdown of concepts into abstractions.
Class
    Definition of a new abstraction.
        Creates n.

Imperative
    Line by line., top to bottom.
Declarative
    You ask questions.
    Don't care how you do it, just give it to me.
Procedural
    Call procedures (not functions).
Structured
    Control structure loop/conditional.
OOP

Functional
    There is no global state.
        There is no side effects. (No printing in the middle, it's in the process.)
    There are no computer science 'variables'.
    For example:
        It's not f(x) = 3, it's f(3), it's always there, never changes.
    You can do all of them simultaniously. (Like a google search when finding images.)

Book: 
    7 languages in 7 weeks.
    7 more languges in 7 more weeks.

Bash: (Loosely typed)
    #!/bin/Bash

    food=`echo steak`;
    drink=`echo milk`;
        // can not have spaces in between assignment operators
    return=$?
        // exit code from previous program run
    echo $return
        // use the variable/expression that comes next "$"
        // will output 0
    echo $drink.txt
        // will milk.txt
        // $drink is replaced with what is exactly at the variable "drink"
    gcc prog1_1.can
    `./a.out`

Class Monkey Example **************************************************************

    class Monkey
{
    private:
        int banana;
        int heldbananas;
    public:
        int GetBanana() {
            return this.banana;
        }
        void SetBanana(int b) {
            if (b < 0)
                b = 0;
            banana = b;
        }
        void EatBanana() {
            this.banana++;
        }
        int Run() {
            if (this.banana > 0) {
                this.banana--;
                return 10;
            }
            return 0;
        }
}