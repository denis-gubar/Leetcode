class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) : n(n), lines(vector<vector<int>>(2, vector<int>(2 * n + 2)))	   {

	}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		if (++lines[player - 1][row] == n) return player;
		if (++lines[player - 1][n + col] == n) return player;
		if (row == col && ++lines[player - 1][2 * n] == n) return player;
		if (row + col == n - 1 && ++lines[player - 1][2 * n + 1] == n) return player;
		return 0;
	}
	int n;
	vector<vector<int>> lines;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */