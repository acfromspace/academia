# Assignment #3, kingofthenorth
> Lua implementation with C/C++

Goal is to familiarize with Lua while working with C/C++.

## Content
> 3 sub-assignments in total.

- prog3_1.cpp

Single command line argument. Create a lua environment in the cpp. The program will be compiled similar to this.

```
# g++ prog3_1.cpp -o prog3_1 -I lua-5.3.4/src -L lua-5.3.4/src -l lua -l m -l dl
```

- prog3_2.lua

Implement the Infix to Postfix function within lua using function: "InfixToPostfix(str)". Tokenize input string to space to space then apply the infix of postifx.

- prog3_3.cpp

Extension of prog3_1.cpp. Combines both the previous programs printing out the "InfixToPostfix(str)".

Procedurally, lua environment created, run programs by command line argument, take user input, call InfixToPostfix function, retrieve the postfix from the infix (via lua stack), and then print the string.