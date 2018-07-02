# @author       acfromspace
# @filename     checkers.py
# @description  Assignment 3
# @class        CS 550
# @instructor   Roch
# @notes        N/A

import imp
import sys
major = sys.version_info[0]
minor = sys.version_info[1]
modpath = "__pycache__/tonto.cpython-{}{}.pyc".format(major, minor)
tonto = imp.load_compiled("tonto", modpath)
import tonto
# tonto - Professor Roch's not too smart strategy
# You are not given source code to this, but compiled .pyc files
# are available for Python 3.5 and 3.6 (fails otherwise).
# This will let you test some of your game logic without having to worry
# about whether or not your AI is working and let you pit your player
# against another computer player.
#
# Decompilation is cheating, don't do it.

import time
import datetime
import boardlibrary
import checkerboard

# ai - ai player
import ai

# human - human player, prompts for input
import human


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


def Game(red=ai.Strategy, black=tonto.Strategy,
         maxplies=3, init=None, verbose=True, firstmove=0):
    """Game(red, black, maxplies, init, verbose, turn)
    Start a game of CS550Assignment3
    red,black - Strategy classes (not instances)
    maxplies - # of turns to explore (default 10)
    init - Start with given board (default None uses a brand new game)
    verbose - Show messages (default True)
    firstmove - Player N starts 0 (red) or 1 (black).  Default 0. 
    """

    # Don't forget to create instances of your strategy,
    # e.g. black('b', checkerboard.CheckerBoard, maxplies)

    print("================================ Checkers =================================")
    print("CS 550 Artificial Intelligence | Prof. Roch | Assignment 3 | Andrew De Leon")
    print("============================= Creating game... ============================")

    game_board = checkerboard.CheckerBoard()
    red_player = red('r', game_board, maxplies)
    black_player = black('b', game_board, maxplies)
    turn_counter = 1
    players = [red_player, black_player]
    game_start = time.time()

    while True:
        turn_start = time.time()

        turn_counter = turn_counter % 2 - 1

        game_board = players[turn_counter].play(game_board)[0]
        print("RED MADE A MOVE!\n", game_board)

        current = time.time()

        print("Turn time: {} | Game time: {}".format(
            elapsed(turn_start, current), elapsed(game_start, current)))

        turn_start = time.time()

        turn_counter = turn_counter % 2 - 1

        game_board = players[turn_counter].play(game_board)[0]
        print("BLACK MADE A MOVE!\n", game_board)

        current = time.time()

        print("Turn time: {} | Game time: {}".format(
            elapsed(turn_start, current), elapsed(game_start, current)))

        if game_board.is_terminal()[0]:
            print("Game finished!\n")
            break


if __name__ == "__main__":
    Game()
