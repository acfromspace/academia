"""
ai - search & strategy module

implement a concrete Strategy class and AlphaBetaSearch
"""

import checkerboard
import abstractstrategy


class Strategy(abstractstrategy.Strategy):
    depth = 0
    start_count = True

    def __init__(self, maxplayer, game, maxplies):
        super(Strategy, self).__init__(maxplayer, game, maxplies)
        self.find = AlphaBetaSearch(self, maxplayer, self.minplayer, maxplies=maxplies, verbose=False)

    def utility(self, board):
        # Returns best value
        value = self.check_pieces(board)
        value += self.check_dist(board)
        value += self.check_jump(board)

        return value

    def check_pieces(self, board):
        # Checks available pieces
        pawn_value = board.get_pawnsN()[board.playeridx(self.maxplayer)] - \
                     board.get_pawnsN()[board.playeridx(self.minplayer)]
        king_value = board.get_kingsN()[board.playeridx(self.maxplayer)] - \
                     board.get_kingsN()[board.playeridx(self.minplayer)]
        return pawn_value + (1.5 * king_value)

    def check_dist(self, board):
        # Check distance to upgrading to King
        value = 0

        for row, col, piece in board:
            (player, is_king) = board.identifypiece(piece)
            if not is_king:
                if player is board.playeridx(self.maxplayer):
                    value += board.disttoking(piece, row)
                else:
                    value -= board.disttoking(piece, row)
            if self.on_edge:
                if player is self.maxplayer:
                    value += board.edgesize
                else:
                    value -= board.edgesize
        return value

    def check_jump(self, board):
        # Finds number of jumps by difference of total of previous board and current board
        if self.start_count:
            self.rev_piececounter = self.curr_piececounter = self.amount_pieces(board)
            self.start_count = False
        self.prev_piececounter = self.curr_piececounter
        self.curr_piececounter = self.amount_pieces(board)
        # If maxplayer loses less pieces than the minplayer, take jump
        if (self.prev_piececounter[0] - self.curr_piececounter[0] <
                self.prev_piececounter[1] - self.curr_piececounter[1]):
            # Minplayer pieces taken
            return self.prev_piececounter[1] - self.curr_piececounter[1]
        else:
            # Maxplayer pieces lost
            return self.prev_piececounter[1] - self.curr_piececounter[1] - \
                   self.prev_piececounter[0] - self.curr_piececounter[0]

    def amount_pieces(self, board):
        # Total number of pawns/kings on board
        return [board.get_pawnsN()[board.playeridx(self.maxplayer)] +
                board.get_kingsN()[board.playeridx(self.maxplayer)],
                board.get_pawnsN()[board.playeridx(self.minplayer)] +
                board.get_kingsN()[board.playeridx(self.minplayer)]]

    def on_edge(self, board, row, col):
        # Checks if on edge
        if row is 0 or row is (board.edgesize - 1) or col is 0 or col is (board.edgesize - 1):
            return True
        return False

    def play(self, board):
        # Returns updated board as well as resetting depth of search
        self.depth = 0
        action = self.find.alphabeta(board)
        if action:
            update = board.move(action)
        else:
            update = board
        return update, action


class AlphaBetaSearch(object):
    """
    AlphaBetaSearch - Conduct alphabeta search
    """
    inf = float('inf')

    def __init__(self, strategy, maxplayer, minplayer, maxplies=3, verbose=False):
        """
        AlphaBetaSearch - Initialize a class capable of alphabeta search

        :param strategy: implementation of AbstractStrategy class
        :param maxplayer: name of player that will maximize
        :param minplayer: name of player that will minimize
        :param maxplies: maximum depth
        :param verbose: debug info
        """
        self.strategy = strategy
        self.maxplayer = maxplayer
        self.minplayer = minplayer
        self.maxplies = maxplies
        self.verbose = verbose

    def alphabeta(self, state):
        # Implementation of alpha-beta
        best_value = self.max_value(state=state, alpha=(-self.inf), beta=self.inf)
        # Compares all possible actions and chooses the best one.
        actions = state.get_actions(self.maxplayer)
        for action in actions:
            value = self.strategy.utility(state.move(action))
            if abs(best_value - value) < 1:
                return action

    def max_value(self, state, alpha, beta):
        # Implementation of max value
        terminal = state.is_terminal()
        util_value = 0
        # Checks if the current state is a terminal node
        if terminal[0] is True:
            util_value = self.strategy.utility(state)
        # Get values from the children nodes of this state
        else:
            value = (-self.inf)
            # Return if this search has already reached the designated maxplies
            if self.strategy.depth > self.maxplies:
                return value
            self.strategy.depth += 2
            for action in state.get_actions(self.maxplayer):
                # Compare which has the higher value
                value = max(value, self.min_value(state=state.move(action), alpha=alpha, beta=beta))
                # Store the utility value of the state since value will constantly grab infinity after first run
                util_value = self.strategy.utility(state.move(action))
                if util_value >= beta:
                    break
                else:
                    alpha = max(alpha, util_value)
        return util_value

    def min_value(self, state, alpha, beta):
        # Implementation of min value
        terminal = state.is_terminal()
        # Checks if the current state is a terminal node
        if terminal[0] is True:
            util_value = self.strategy.utility(state)
        # Get values from the children nodes of this state
        else:
            value = self.inf
            for action in state.get_actions(self.minplayer):
                # Return if this search has already reached the designated maxplies
                if self.strategy.depth > self.maxplies:
                    return value
                # Compare which has the lower value
                value = min(value, self.max_value(state=state.move(action), alpha=alpha, beta=beta))
                # Store the utility value of the state since value will constantly grab -infinity after first run
                util_value = self.strategy.utility(state.move(action))
                if util_value <= alpha:
                    break
                else:
                    beta = min(beta, util_value)
        return util_value