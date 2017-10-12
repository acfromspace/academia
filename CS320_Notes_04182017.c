TEST.C: ************************************

#include <stdio.h>

// or #include "lua.hpp"

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

using namespace std;

int main(int argc, char** argv)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    lua_dofile(L,argv[1]);

    cout << "Type things" << endl;

    getline(cin,s);

    luaL_dostring("func(" + s + ")"); // figure out to concatinate strings in c++

    lua_close(L);

    return 0;
}

CMD LINE: **********************************

make linux
make clean
SUDO APT-GET INSTALL LIBREADLINE-DEV
gcc test.c -I lua-5.3.4/src/ -l lua
g++ test.cpp -I lua-5.3.4/src/ -l lua
    - l lua links the lua library

- llex.o is the parser
- ls, look for lua, luac, liblua.a in CS320Assignment3/lua-5.3.4/src

./a.out something.lua

LUA FILE: **********************************
*save as something.lua

print("Hello!");

*****

function func(str)
    print("FROM LUA"..str);
    return str .. "hello world"
end

********************************************

list comprehension
    use for loops to construct list
    introduction to functional list programming
        L = []
        for i in range(1, 100):
            L[i] = func(i)

Python is late bound, C is early bound.
    BINDINGS
        - when do we know which function is going to be called?
    EARLY
        - we know which function will be called during compile time

More Python coding
    Go over chpaters 4, 5, 6 of the parking project