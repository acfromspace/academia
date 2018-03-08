from board import Board
from random import shuffle

import math


class TileBoard(Board):

    def __init__(self, boardSize, force_state=None):
        """ Initializes an n-puzzle of size n.

        :param boardSize: Amount of values to be distributed.
        :param force_state: Specifies if user wants a random list or a user-created list
        """
        self.size = boardSize + 1
        self.possibleMoves = []
        super().__init__(int(math.sqrt(self.size)), int(math.sqrt(self.size)))
        if force_state is None:
            self.populate(self.create_values(self.size))
            while not self.solvable():
                print("Shuffling: ", self.board)
                self.shuffle()
        # Optional force_state is not specified

    def __eq__(self, other):
        """ Checks if two tile boards are in the same state.

        :param other: The board to be compared to.
        :return: Other data structure to be equal to current data structure.
        """
        print("Calling equals()")
        return self.state_tuple() == other.state_tuple()

    def blank(self):
        """ Finds where the None is located.

        :return: Blank location.
        """
        for counter, elements in enumerate(self.state_tuple()):
            if elements is None:
                blank_row = counter // super().get_rows()
                blank_col = counter % super().get_cols()
        blank_area = [blank_row, blank_col]
        return blank_area

    def create_values(self, boardSize):
        """ Checks size and creates the appropriate needed values.

        :param boardSize: Amount of values to be distributed.
        :return: Elements.
        """
        print("Calling create_values()")
        elements = [counter for counter in range(1, boardSize)]
        elements.append(None)
        print("Values to be used in the board:", elements)
        shuffle(elements)
        return elements

    def get_actions(self):
        """ Looks for the valid moves to perform.

        :return: Possible moves to do.
        """
        print("Calling get_actions()")
        self.possibleMoves = []
        wall = int(math.sqrt(self.size)) - 1
        row, col = self.blank()[0], self.blank()[1]

        if col is not 0:
            print("You can go LEFT.")
            self.possibleMoves.append([0, -1])  # Left
        if col is not wall:
            print("You can go RIGHT.")
            self.possibleMoves.append([0, 1])  # Right
        if row is not 0:
            print("You can go UP.")
            self.possibleMoves.append([-1, 0])  # Up
        if row is not wall:
            print("You can go DOWN.")
            self.possibleMoves.append([1, 0])  # Down

        return self.possibleMoves

    def move(self, offset):
        """ Changes blank position with a valid tile position.

        :param offset: Distance to be changed.
        :return: New positions for blank and valid tile position.
        """
        print("Calling move()")

        if offset not in self.possibleMoves:
            print("!!!!!!!!! ERROR! Invalid move, try again. !!!!!!!!!")
        else:
            move0, move1 = offset[0], offset[1]
            start0, start1 = self.blank()[0], self.blank()[1]
            end0, end1 = start0 + move0, start1 + move1
            self.board[start0][start1], self.board[end0][end1] = self.board[end0][end1], self.board[start0][start1]

    def populate(self, elements):
        """ Receives the create_values() list and transfers to the tile board accordingly.

        :param elements: Valid values made by create_values()
        :return: Working tile board.
        """
        print("Calling populate()")
        for counter, elements in enumerate(elements):
            row = counter // super().get_rows()
            col = counter % super().get_cols()
            self.place(row, col, elements)
        print(self.board)

    def shuffle(self):
        """ Shuffles the data structure.

        :return: Shuffled data structure.
        """
        print("Calling shuffle()")
        shuffling = list(self.state_tuple())
        shuffle(shuffling)
        self.populate(shuffling)
        return tuple(shuffling)

    def solvable(self):
        """ Checks inversion order to see if the board is solvable.

        :return: True or false depending if board is able to be solved.
        """
        print("Calling solvable()")

        check = list(self.state_tuple())

        remember = 0
        for counter in range(0, len(check)):
            if check[counter] is None:
                remember = counter
        check.remove(check[remember])
        print("'None' is removed for check:", check)

        inversions = 0
        for counter in range(0, len(check)):
            for compare in range(counter, len(check)):
                if check[counter] > check[compare]:
                    inversions = inversions + 1
        print("Number of inversions in data structure is:", inversions)
        if inversions % 2 == 0:
            solvable = True
        else:
            solvable = False

        print('Solvable?:', solvable)

        return solvable

    def solved(self):
        """ Checks to see if the tile board is solved or not.

        :return: Prompt if the tile board is solved or not.
        """
        print("Calling solved()")

        check = list(self.state_tuple())

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

    def state_tuple(self):
        """ Flatten the list of list representation of the board and cast it to a tuple.

        :return: Turns [[1,2,3],[4,None,5],[6,7,8]] becomes (1,2,3,4,None,5,6,7,8).
        """
        elements = []
        for counter in self.board:
            for element in counter:
                elements.append(element)
        return tuple(elements)
