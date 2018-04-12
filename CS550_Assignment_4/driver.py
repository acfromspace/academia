from csp_lib.sudoku import (Sudoku, easy1, harder1)
from constraint_prop import AC3
from csp_lib.backtrack_util import mrv
from backtrack import backtracking_search

# Self-imported library
import time

"""
Author: Andrew De Leon
Description: CS 550, Assignment #4
"""

# Implemented time management code from Assignment #3

def elapsed(earlier, later):
    """elapsed - Convert elapsed time.time objects to duration string

    Useful for tracking move and game time.  Example pseudocode:

    gamestart = time.time()

    while game not over:
        movestart = time.time()
        ...  logic ...
        current = time.time()
        print("Move time: {} Game time: {}".format(
            elapsed(movestart, current), elapsed(gamestart, current))


    """
    return time.strftime('%H:%M:%S', time.gmtime(later - earlier))


def game():
    print("================================= Sudoku ==================================")
    print("CS 550 Artificial Intelligence | Prof. Roch | Assignment 4 | Andrew De Leon")
    print("============================= Creating game... ============================")

    game_start = time.time()

    for puzzle in [easy1, harder1]:

        # Creates an instance of the puzzle to work with
        s = Sudoku(puzzle)

        # Creates a viewable interface of the working sudoku puzzle
        print("\nInitial problem:")
        s.display(s.infer_assignment())

        # Applies the AC3 constraint
        AC3(s)
        print("\nAfter AC3 constraint propagation applied!")

        # Keeps track of time of the puzzle
        puzzle_start = time.time()

        # If goal is not reached yet, keep trying to find a solution
        if not s.goal_test(s.curr_domains):
            print("\nBacktracking search starting...")
            result = backtracking_search(s, select_unassigned_variable=mrv)
            if result:
                # Success
                print("\nBacktracking solution:")
                s.display(s.infer_assignment())
            else:
                # Failure
                print("\nBacktracking failed! :(")

        current = time.time()

        # Time information to be relayed
        print("\nPuzzle time: {} | Overall time: {}".format(elapsed(puzzle_start, current), elapsed(game_start, current)))


if __name__ == "__main__":
    game()

# easy1 = '..3.2.6..9..3.5..1..18.64....81.29..7.......8..67.82....26.95..8..2.3..9..5.1.3..'
# harder1 = '4173698.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......'
