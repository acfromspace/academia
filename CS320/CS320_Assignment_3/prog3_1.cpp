// compile = g++ prog3_1.cpp -o prog3_3 -I lua-5.3.4/src -L lua-5.3.4/src -l lua -l m -l dl
// ' ./prog3_1 '

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** agrv) {

    cout << "Assignment #3-1, kingofthenorth, kingofthenorth@gmail.com\n";

    // create a new lua state
    lua_State *Environment = luaL_newstate();
    // open all libaries
    luaL_openlibs(Environment);
    // reference to file
    luaL_dofile(Environment, "test.lua");

    cout << "Hello World - How are you?";

    lua_close(Environment);   

    return 0;
}
