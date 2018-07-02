import math

from basicsearch_lib02.tileboard import TileBoard
from basicsearch_lib02.searchrep import Problem

class NPuzzle(Problem):
    """
    NPuzzle - Problem representation for an N-tile puzzle
    Provides implementations for Problem actions specific to N tile puzzles.
    """
    def __init__(self, n, force_state=None, **kwargs):
        """"__init__(n, force_state, **kwargs)
        
        NPuzzle constructor.  Creates an initial TileBoard of size n.
        If force_state is not None, the puzzle is initialized to the
        specified state instead of being generated randomly.
        
        The parent's class constructor is then called with the TileBoard
        instance any any remaining arguments captured in **kwargs.
        """

        # Calls parent class constructor
        super().__init__(n, force_state, **kwargs)

        # Note on **kwargs:
        # **kwargs is Python construct that captures any remaining arguments 
        # into a dictionary.  The dictionary can be accessed like any other 
        # dictionary, e.g. kwargs["keyname"], or passed to another function 
        # as if each entry was a keyword argument:
        #    e.g. foobar(arg1, arg2, …, argn, **kwargs).

    def actions(self, state):
        print("NPuzzle.actions()")
        "actions(state) - find a set of actions applicable to specified state"

        # Pass state somehow

        actions = []
        # check row and column, no diagonal moves allowed
        boarddims = [self.get_rows(), self.get_cols()]
        for dim in [0, 1]:  # rows, then columns
            # Append offsets to the actions list,
            # e.g. move left --> (-1,0)
            #      move down --> (0, 1)
            # Note that when we append to the list of actions,
            # we use list( ) to make a copy of the list, otherwise
            # we just get a pointer to it and modification of offset
            # will change copies in the list.
            offset = [0, 0]
            # add if we don't go off the top or left
            if self.empty[dim] - 1 >= 0:
                offset[dim] = -1
                actions.append(list(offset))
            # append if we don't go off the bottom or right
            if self.empty[dim] + 1 < boarddims[dim]:
                offset[dim] = 1
                actions.append(list(offset))

        # Go ahead and perform an action, up, right, down, left

        return actions
    
    def result(self, state, action):
        "result(state, action)- apply action to state and return new state"

        # Looking at the state given, explore options from up, right, down, left
        # Keep exploring till goal is found

        raise NotImplemented
    
    def goal_test(self, state):
        # Pass state somehow

        print("Calling solved()")

        check = list(TileBoard.state_tuple())

        correct = 1
        # Checks if none is in the correct location which is the middle of the list
        if check[(len(check) // 2)] is None:
            correct += 1
        for counter in range(0, len(check)):
            if counter < (len(check) // 2):
                if check[counter] is counter + 1:
                    correct += 1
                else:
                    continue
            elif counter > math.ceil(len(check) / 2):
                if check[counter] is counter:
                    correct += 1
                else:
                    continue
        if correct is len(check):
            print("Puzzle is solved!")
            return True
        else:
            print("Puzzle is not solved.")
            return False

    
        



