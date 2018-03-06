WOO NOTES! Missed 3/07***

prog2_1.cpp

prog2_2.cpp
    error from tokenizer
    does your tokenizer work with 2_2.cpp
    does Scott''s tokenizer work with your 2_2.cpp

GetTokens(); should keep repeating until a correct input is achieved.

LUA **********

***** Example 1:
if
then

end

***** Example 2:
if
then

else if
then

end

***** Example 3:
for i = 1, 10, 2
do

end

***** Example 4:
for k,v in pairs(A)
do

end
A = {10, 15, 20}
A["Hello"] = "World"

key = 2, value = 15

***** Example 5:
while
do

end

***** Example 6:
repeat
do

until

***** Example 7:
Lambda function (anonymous functions)

function (x, y)
    return x + y
end

***** Example 8:
function AdderGenerator(int i)
    return function (x)
        return x + i
    end
end

Adders = {}
for n = 1, 100000
do
    Adders[n] = AdderGenerator(n)
end

Adders[50](10)

***** Example 9:
function Add1(x)
    return x + 1
end

function mult5(x)
    return x * 5
end

function Composition(f, g)
    return function (x)
        returns f(g(x))
    end
end

Composition(Add1, Mult5)

OBJECT ORIENTED PROGRAMMING
    Model <-> Class Based OOP
        Description of extant objects
            Blueprint -> House
                Pro: Every instance of the blueprint is identical
                Con: Difficult to make changes

    Model <-> Prototype Based OOP
            Prototype -> House
                Pro: Easy to modify
                Con: Not all things may be the same
                Build a house! Foundations, walls, roof
                    OH NO FORGOT THE PIPES

    Orc = { }
    Orc["Health"] = 75
    Orc["Damage"] = 30

    Encapsulation
    Inheritance
    Polymorphism
    Interfaces
