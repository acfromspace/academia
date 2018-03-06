Assignment #3 Lua Tokenizer

2 Programs, 3 Parts

Not a defined output for any of them besides the headers

1) C++
    Create and make Lua environment (similar to C)
2) Lua
    Infix to postfix notation
    EXAMPLE:
        function InPost(str)
        ...
        return post
        end

Look at Lua documentation it'll be on the Blackboard assignment

*****************************************************************************
Different programming paradigms
*****************************************************************************
- "A way to program" Google.

    Procedural -
        You have procedures and you can call them.

    O.O.P. - 
        The ability to think/program in things inheritance/poly/A.S./Aggregation

        Aggregation -
            If an NPC picks a specific weapon, their behavior changes.

            class NPC {
                weapon mine;

                void DoStuff();
                    if mine == null
                        DoSTDBehavior();
                    else
                        mine.DoBehavior(this);
            }

            class Weapon {
                DoBehavior(owner)
            }

            (So you would)

    Structured -
        You have scoped control structures. if/else/loops/switch

    Imperative -
        Start at beginning go to end, execute.
        "A progammer tells what to do, not the problem you're trying to solve"

    Declarative -
        Ask for solutions to problems, not how to solve them.
        "SQL"

    Logical -
        Discover relationships between data. (Expert Systems as in can make predictions and can plan to solve problems.)
        100% A.I.

        Example:
        Light is green, person is stopped, person is probably on their phone.

    Functional -
        Problems are solved w/ recurrence relationships.
            No traditional CS variables.
            Only have parameters.
            Almost can use infinite sequences.

            Example:
            foo(a,b)
            7 = foo(3,2)
                will always be 7

            f(x) = x^3 + 3

    Interpretive -
         BASIC, C, Lisp, Pascal, and Python.
         Made from other languages.

*****************************************************************************
REPL.it
*****************************************************************************

import math
def IsPrime(x):
    if x ==2:
        return true
    for i in range(2,math.ceil(math.sqrt(x))):
        print(i)
        print(x)
        if x % i == 0:
            return false
    return true

CMD LINE:
    [x for x in range(100, 1000) if IsPrime(x)]

    import math
    math.factorial(1000)