'''
Constraint propagation
'''

"""
Author: Andrew De Leon
Description: CS 550, Assignment #4
"""

def AC3(csp, queue=None, removals=None):
    """AC3 constraint propagation
    
    """

    # Hints:
    # Remember that:
    #    csp.variables is a list of variables
    #    cps.neighbors[x] is the neighbors of variable x


    if queue is None:
        queue = [(first, third) for first in csp.variables for third in csp.neighbors[first]]

    # Copies the current set of domains to one called curr_domains which will be the affected data structure
    csp.support_pruning()

    # Construct queue of arcs
    for first in csp.variables:
        for third in csp.neighbors[first]:
            queue.append((first, third))

    # Go through queue if it's not empty
    while queue:
        (first, second) = queue.pop()
        if recurse(csp, first, second, removals):
            # If domain is 0, no solution is to be found
            if len(csp.curr_domains[first]) is 0:
                return False
            else:
                for third in csp.neighbors[first]:
                    queue.append((third, first))
    return True


def recurse(csp, first, second, removals):
    revised = False

    for counter in csp.curr_domains[first]:
        # Check if no value "y" in domain of "second" allows counter, y to satisfy the constraint put by (first, second)
        if all(not csp.constraints(first, counter, second, y) for y in csp.curr_domains[second]):
            csp.prune(first, counter, removals)
            revised = True

        return revised
