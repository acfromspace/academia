Lua doString

www.lua.org/manual/5.3/manual.html#luaL_dostring

cpp

getline(cin,s);

s = "return foobar('" + s + "')";

luaL_dostring(L,s.c_str());

const char *ret = lua_tostring(L,-1);

-- you can replace const char *ret with "s"
-- s = lua_tostring(L,-1);

s = ret;

-- using fflush(NULL);
-- forces print outs to occur

--for lua
--function nameless
--    return foobar('stuff')
--return

pop + - * / % nil

is nil on top of the stack, pop

push nil
pop + -
push + -

0 = nil
1 = + -
2 = * / %