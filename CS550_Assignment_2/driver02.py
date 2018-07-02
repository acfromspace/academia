'''
driver for graph search problem
Created on Feb 10, 2018

@author: mroch
'''

from statistics import (mean, stdev)  # Only available in Python 3.4 and newer

from npuzzle import NPuzzle
from basicsearch_lib02.tileboard import TileBoard
from searchstrategies import (BreadthFirst, DepthFirst, Manhattan)
from problemsearch import graph_search
import collections
import time
import searchstrategies


def tic():
    "Return current time representation"
    return time.time()

def tock(t):
    "Return time elapsed in sec since t where t is the output of tic()"
    return time.time() - t

def driver() :
    size = 8  # Hardcoded size.
    board = TileBoard(size)

    print("================================= TileBoard Game =================================")
    print("CS 550 Artificial Intelligence | Prof. Roch | Assignment 2 | Andrew De Leon")
    print("=========================== Creating solvable board... ===========================")
    print("Method checker:")
    print("state_tuple():", board.state_tuple())
    print("get_actions():", board.get_actions())
    print("solved():", board.solved())

    while not board.solved():
        print("====================================== Board =====================================")
        print(board)
        print("Actions:", board.get_actions())

        break

    print("End of program.")

        # Create 31 tileboards and run them all to compare solutions amongst them via time

"""
def input_validation(prompt):
    while True:
        try:
            user_input = input(prompt)
        if user_input is "a":
            next_input = [0, -1]  # Left.
        elif user_input is "d":
            next_input = [0, 1]  # Right.
        elif user_input is "w":
            next_input = [-1, 0]  # Up.
        elif user_input is "s":
            next_input = [1, 0]  # Down.
        else:
            break

    return next_input
"""

if __name__ == '__main__':
    driver()
    # input_validation()