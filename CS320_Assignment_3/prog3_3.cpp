// compile = g++ prog3_3.cpp -o prog3_3 -I lua-5.3.4/src -L lua-5.3.4/src -l lua -l m -l dl
// ' ./prog3_3 '

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** agrv) {

    cout << "Assignment #3-3, Andrew Christopher De Leon, andrewchristopherdeleon@gmail.com";

    string s;

    // create a new lua state
    lua_State *Environment = luaL_newstate();
    // open all libaries
    luaL_openlibs(Environment);
    // reference to file
    luaL_dofile(Environment, "prog3_2.lua");

    cout << "Prompt: " << endl;

    getline(cin,s);

    s = "return InfixToPostfix('" + s + "')";

    luaL_dostring(Environment,s.c_str());

    lua_close(Environment);   

    return 0;
}
