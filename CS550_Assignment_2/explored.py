'''
Created on Feb 8, 2018

@author: mroch
'''
class Explored(object):
    "Maintain an explored set.  Assumes that states are hashable"

    def __init__(self):
        "__init__() - Create an empty explored set"

        self.explored = {}

        raise NotImplemented
        
    def exists(self, state):
        """exists(state) - Has this state already been explored?
        Returns True or False, state must be hashable
        """

        # if the state is added, it has been explored
        # return true or false accordingly

        raise NotImplemented
    
    def add(self, state):
        """add(state) - add given state to the explored set.  
        state must be hashable and we asssume that it is not already in set
        """

        # For whatever state the tileboard is in, add it to the exists pile

        state = self.exists()

        # The hash function is a Python builtin that generates
        # a hash value from its argument.  Use this to create
        # a dictionary key.  Handle collisions by storing 
        # states that hash to the same key in a bucket list.
        # Note that when you access a Python dictionary by a
        # non existant key, it throws a KeyError

        raise NotImplemented
            
