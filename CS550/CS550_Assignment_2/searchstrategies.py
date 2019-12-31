# @author       kingofthenorth
# @filename     searchstrategies.py
# @description  Assignment 2
# @class        CS 550
# @instructor   Roch
# @notes        N/A

"""
searchstrategies

Module to provide implementations of g and h for various search strategies.
In each case, the functions are class methods as we don't need an instance
of the class.  

If you are unfamiliar with Python class methods, Python uses a function
decorator (indicated by an @ to indicate that the next method is a class
method).  Example:

class SomeClass:
    @classmethod
    def foobar(cls, arg1, arg2):
        "foobar(arg1, arg2) - does ..."
        
        code... class variables are accessed as cls.var (if needed)
        return computed value

A caller would import SomeClass and then call, e.g. :  
    SomeClass.foobar("hola","amigos")

Contains g and h functions for:
BreadFirst - breadth first search
DepthFirst - depth first search
Manhattan - city block heuristic search.  To restrict the complexity of
    this, you only need handle heuristics for puzzles of an odd length
    with solutions that contain the blank in the middle and numbers going
    from left to right in each row, e.g.:
        123
        4 5
        678
    When mulitple solutions are allowed, the heuristic becomes a little more
    complex as the city block distance must be estimated to each possible solution
    state. 
"""

# For each of the following classes, create classmethods g and h
# with the following signatures
#       @classmethod
#       def g(cls, parentnode, action, childnode):
#               return appropritate g value
#       @classmethod
#        def h(cls, state):
#               return appropriate h value

from basicsearch_lib02.searchrep import Node
from basicsearch_lib02.tileboard import TileBoard


class BreadthFirst:

    counter = 0

    @classmethod
    def g(cls, parentnode: Node, action, childnode: Node):
        return len(childnode.path())

    @classmethod
    def h(cls, state):
        return cls.counter


class DepthFirst:

    @classmethod
    def g(cls, parentnode: Node, action, childnode: Node):
        return (parentnode.depth + 1) * -1

    @classmethod
    def h(cls, state: TileBoard):
        return 0


class Manhattan:

    @classmethod
    def g(cls, parentnode, action, childnode: Node):
        return childnode.depth * 2

    @classmethod
    def h(cls, state: TileBoard):
        manhattan_solution = 0

        solved = [[None for c in range(state.cols)] for r in range(state.rows)]
        index = 1
        for row in range(state.boardsize):
            for col in range(state.boardsize):
                if row == state.rows // 2 and col == state.cols // 2:
                    solved[row][col] = None
                else:
                    solved[row][col] = index
                    index += 1

        # Calculate distance to solution
        for row in range(state.boardsize):
            for col in range(state.boardsize):
                item = state.get(row, col)
                for solved_row in range(len(solved)):
                    manhattan_solution += abs(solved_row - row) + \
                        abs(solved[solved_row].index(item) - col)

        return manhattan_solution
