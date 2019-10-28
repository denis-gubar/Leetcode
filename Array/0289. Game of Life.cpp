class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>> result(board);
		for(int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
			{
				int count = 0;
				for (int dx = -1; dx <= 1; ++dx)
					for (int dy = -1; dy <= 1; ++dy)
						if (i + dx >= 0 && i + dx < board.size() && j + dy >= 0 && j + dy < board[0].size())
							count += board[i + dx][j + dy];
				result[i][j] = (count == 3 || count == 4 && board[i][j]);					
			}
		result.swap(board);
	}
};