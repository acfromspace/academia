# @author       acfromspace
# @filename     driver.py
# @description  Assignment 1
# @class        CS 550
# @instructor   Roch
# @notes        N/A

from boardtypes import TileBoard

def driver():

    print("============================= TileBoard Game =============================")
    print("CS 550 Artifical Intelligence | Prof. Roch | Assignment 1 | Andrew De Leon")
    print("======================= Creating solvable board... =======================")
    size = 8  # Hardcoded size.

    board = TileBoard(size)
    solved = board.solved()

    while not solved:
        print("================================= Controls ===============================")
        print("a = left")
        print("d = right")
        print("w = up")
        print("s = down")
        print('To quit, simply type in "q" or "Q".')
        print("================================== Board =================================")
        print(board)

        board.get_actions()
        user_input = input("Enter a valid move:")

        # If the user wants to quit.
        if str(user_input) is "q" or str(user_input) is "Q":
            return

        if user_input is "a":
            next_input = [0, -1]  # Left.
        if user_input is "d":
            next_input = [0, 1]  # Right.
        if user_input is "w":
            next_input = [-1, 0]  # Up.
        if user_input is "s":
            next_input = [1, 0]  # Down.

        board.move(next_input)

        # Check if the board is solved of not.
        solved = board.solved()

    print("Congratulations, you did it!")


if __name__ == '__main__':
    driver()
