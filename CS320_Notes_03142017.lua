Meta-tables
    It''s tables about tables.
    Use white text to put in your resume because computers track it, but human can''t see it.
        -- THIS IS VERY SMART
        This is why sometimes during a google search brings up things super unrelated to your search.

Meta-functions
    Functions that describe how keys should be retrived from tables and metatables.

TIPS **********************************************

Only one data structure in Lua is called a table.

CODE **********************************************

A = { }
A[A] = a

print(A[1000]) -- No such things as bounds in Lua

print(B["food"]) -- Prints whatever is in "food"

print("Hello World!") -- 1 way to print

io.write('Hello World!\n') -- another way to print

-- specific class (child) w/ higher class (adult)
class Dolphin:Mammal
{

}

class Truck:Automobile
{

}

***************************************************

object = { }

function object.new(parent, child)
    -- parent is the parent of the next object
    -- function object:new (child)
    local obj = child or {}
    setmetatable(obj,parent)
    -- can dynamically change the parent table which makes this super strong
    -- child loses everything if the parent changes so make sure to save to child
    -- setmetatable(obj, self)
    parent.__index = parent
    -- it's a double underscore _ _
    -- self.__index = self
    return obj
end

***************************************************

LUA 30 LINES OF GOODNESS ***

A = object["new"](object)
A = object.new(object)
-- those two functions up above are the same thing, different format
b = a.new(a)
b = object.new(a)
-- if you use a colon operator make the thing to the left the first parameter
C = B:New()

A = Object:New()
B = A:New()
C = B:New()
  
***************************************************

class Automobile
{
    protected int NumWheels = 4;
    public void PrintWheels(Auto this)
    {
        Sy_(this.NumWheels);
    }
}

class cycle
{
    protected int NumWheels = 2;
}

class Truck:Auto
{

}

***************************************************

A = Object:New()

function A.Print()
    print("from A")
end
function A.Other()
    print("other")
end
B = A.New()
function B.Print()
    print("from B")
end
function B.Something()
    print("Something")
end
C = B.New()
C.Print()
-- "from b"
C.Something()
-- "Something"
C.Other
-- no "other" in C nor B, so goes to A and prints out "other"

A =
{
    x = 3,
    y = 4,
    more = 10,
}

A = Object:New(A)

function A:Print()
    print("from A" .. tostring(self.x))
end
function A:Other()
    print("other" .. tostring(self.x))
end
B = A.New()
function B.Print()
    print("from B" .. tostring(self.x))
    -- looks into A because it has x so it prints "from B 3"
end
function B.Something()
    print("Something" .. tostring(self.more))
    -- "something more"
end
C = B.New()
C.Print()
C.X = 10
C.Print() ??
-- "10"