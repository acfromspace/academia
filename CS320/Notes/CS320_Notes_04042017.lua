Two different programs can work together w/ sockets

One program w/ two languages
    1. Write a bunch of code in language, that is compiled into another language (Transpiling)
    2. You can have libararies for c in c++ (Library Importing)
    3. Languages are built on top of other languages (Many on top of C)

What is a library?
    A bunch of code you can call
        Library has a calling convention
        -> How do we call the functions?

Install Lua into Virtualbox Linux

use lua.org/manual

File names:
mylua.c
stuff.lua

#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int main()
{
    lua_State *L;

    char buff[256];

    L = luaL_newstate();
    lua_openlibs(L);

    luaL_dofile(L,"stuff.lua");
    lua_register(:,"Bob")

    scan("%[^\n]", buff);
}

...

void Printer(char *buff) {
    printf("This is from C: %s---\n", buff);
}

int C_LUA_Printer(lua_State * cur_state) {
    const char* buff = luaL_checkstring(cur)state,1);
    Printer(buff);
    return 0;
}