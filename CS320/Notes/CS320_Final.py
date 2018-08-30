***
VOLUME SOLVER
***


Python solution: **********************************************

Class SingleVariableShape:
    def __init__(self,d):
        self.data = d
    def GetVolume(self):
        return 0

Class Cube(SVS):
    def GetVolume(self):
        return self.data * self.data * self.data

Class Sphere(SVS):
    def GetVolume(self):
        return 4/3 * Math.pi * self.data

LUA solution: **********************************************

object = {}

function object:new(t)
    local obj = for{}
    setmetatable(obj,self)
    self._index = self #metafunction, without this there is no polymorphism
    return obj
end

SVS = {data = 0}

function SVS:GetVolume()
    return 0
end

SVS = object:new(SVS) #creates new objects as in parents, this means SVS is the parent of object

Cube = SVS:new()

function Cube:GetVolume()
    return self.data * self.data * self.data
end

A = Cube:new(data=10)

LUA 2nd solution: **********************************************

SVS = {data = 0}

function SVS:new(d)
    local obj = {}
    obj.data = d
    setmetatable(obj,self)
    self.__ = self
    return obj
end

cube = SVS:new(0)

function Cube:GetVolume()
    return self.data
end

***
DO A BUBBLE SORT
***

LUA solution: **********************************************

function BS(t)
    for i = 1,#t
    do
        for i = 1, #t-1
        do if t[j+1] < t[j]
        temp = t[j]
        t[j] = t[j+1]
        t[j+1] = temp
        end
    end
end

Python solution: **********************************************

def BS(i)
    for i in range(0,len(i)):
        for j in range(0,len(i)-1):
            if ([j+1] < l[i]):
                temp = l[j]
                l[j] = l[j+1]
                l[j+1] = temp

***
DO A BUBBLE SORT
***

LUA solution: **********************************************

function med(A)
    return a[#a/z]
end

Python solution: **********************************************

#put code here

