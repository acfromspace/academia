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

import math

# For each of the following classes, create classmethods g and h
# with the following signatures
#       @classmethod
#       def g(cls, parentnode, action, childnode):
#               return appropritate g value
#       @classmethod
#        def h(cls, state):
#               return appropriate h value

class BreadthFirst:
    "BredthFirst - breadthfirst search"
    """
    BreadthFirst
    
    Starts at the root
    Moves to a child node
    From that node, moves to another neighbor
    Goes left to right, checking all possibilities in a cost equal area
    Always finds the solution
    """


    def g(self, parentnode, action, childnode):
        frontier = Queue() # Use Queue class, how?
        frontier.put(parentnode)
        parentnode = {0: None}

        while not childnode.empty():
            current = childnode.get()

            # if current = goal node, break g

            for next in action(current):
                if next not in parentnode:
                    frontier.put(next)
                    parentnode[next] = current

    def h(self, state):
        # check state
        # if state is equal to board.solved() return distance between current node and goal node
        return True
    pass

class DepthFirst:
    "DepthFirst - depth first search"
    """
    DepthFirst
    
    Starts at a node
    Moves to a child node
    From that node, moves to a child
    Continues down a path until it's stuck, that's why it's depth-first
    Back tracks until it finds an unvisited node
    Otherwise known as the "greedy" algorithm
    """

    def g(self, parentnode, action, childnode):
        frontier = Queue()  # Use Queue class, how?
        frontier.put(parentnode)
        parentnode = {0: None}

        while not childnode.empty():
            current = childnode.get()

            # if current = goal node, break g

            for next in action(current):
                if next not in parentnode:
                    frontier.insert(next)
                    parentnode[next] = current

    def h(self, state):
        # check state
        # if state is equal to board.solved() return distance between current node and goal node
        return True

    pass
        
class Manhattan:
    "Manhattan Block Distance heuristic"
    """
    Manhattan
    
    Checks distance by how many moves a node has to move to a specific location.
    If node is at 0,0 and must be at 2,2, it moves 4 spaces to be in the area, not including diagonals.
    If node is at 1,1 and must be at 0,1, it moves 1 space to be in the area.
    To calculate you would take the absolute values of respective axis, subtract them, then add the whole
        data structure to get a distance
        
    return abs(a.x - b-x) + abs(a.y - b.y)
    """

    def g(self, parentnode, action, childnode):
        frontier = Queue()  # Use Queue class, how?
        frontier.put(parentnode)
        parentnode = {0: None}

        while not childnode.empty():
            current = childnode.get()

            # if current = goal node, break g

            for next in action(current):
                if next not in parentnode:
                    frontier.put(next)
                    parentnode[next] = current

    def h(self, state):
        # check state
        # if state is equal to board.solved() return distance between current node and goal node
        # return abs(a.x - b-x) + abs(a.y - b.y)
        return True

    pass