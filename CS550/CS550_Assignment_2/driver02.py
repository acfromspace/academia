# @author       acfromspace
# @filename     driver02.py
# @description  Assignment 2
# @class        CS 550
# @instructor   Roch
# @notes        N/A

import re
import time
from statistics import (mean, stdev)

from basicsearch_lib02.tileboard import TileBoard
from basicsearch_lib02.utilsdontneed import print_table
from npuzzle import NPuzzle
from problemsearch import graph_search
from searchstrategies import (BreadthFirst, DepthFirst, Manhattan)

TRIAL_SIZE = 50
BOARD_SIZE = 8
SEARCH_METHODS = [BreadthFirst, DepthFirst, Manhattan]

# Output Configuration
DEBUG = False
INFO = True
VERBOSE = False


def tic():
    "Return current time representation"
    return time.time()


def tock(t):
    "Return time elapsed in sec since t where t is the output of tic()"
    return time.time() - t


def driver():
    print("============================= TileBoard Game ==============================")
    print("CS 550 Artificial Intelligence | Prof. Roch | Assignment 2 | Andrew De Leon")
    print("======================== Going through searches... ========================")

    plan_size = dict()
    nodes_size = dict()
    time = dict()

    for method in SEARCH_METHODS:
        plan_size[method] = list()
        nodes_size[method] = list()
        time[method] = list()

    for i in range(TRIAL_SIZE):
        if INFO:
            print('Trial #%d commence...' % (i + 1))

        # Standard layout for the board
        board_layout = TileBoard(BOARD_SIZE).state_tuple()

        # Trying the methods
        for method in SEARCH_METHODS:
            if INFO:
                print('Solving puzzle via %s' % method.__name__)

            puzzle = NPuzzle(BOARD_SIZE, g=method.g,
                             h=method.h, force_state=board_layout)

            start_time = tic()
            path, nodes_explored = graph_search(
                puzzle, debug=DEBUG, verbose=VERBOSE)
            duration = tock(start_time)
            assert path is not None

            plan_size[method].append(len(path))
            nodes_size[method].append(nodes_explored)
            time[method].append(duration)

            if INFO:
                print('Solved puzzle via %s in %d seconds' %
                      (method.__name__, duration))

        print('Finished Trial #%d' % (i + 1))

    if INFO or DEBUG or VERBOSE:
        print("\n\n======================== Going through searches... ========================\n\n\n")

    header = ["Search / Result   ",
              "Plan Size (Mean/STDEV)",
              "Node Size (Mean/STDEV)",
              "Time (Mean/STDEV)"]
    rows = list()

    # Formatting
    rows.append(['-' * (len(header[i]) + 1) for i in range(len(header))])

    for method in SEARCH_METHODS:
        rows.append([' '.join(re.sub('(?!^)([A-Z][a-z]+)', r' \1', method.__name__).split()),
                     '{:.3f} / {:.3f}'.format(
                         mean(plan_size[method]), stdev(plan_size[method])),
                     '{:.3f} / {:.3f}'.format(
                         mean(nodes_size[method]), stdev(nodes_size[method])),
                     '{:.3f} / {:.3f}'.format(mean(time[method]), stdev(time[method]))])

    print_table(rows, header=header, sep="\t| ")


if __name__ == '__main__':
    driver()
