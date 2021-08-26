class Solution {
public:
	bool calc(vector<vector<char>>& board, const string& word, int x, int y, int t)
	{
		if (t == word.size()) return true;
		if (board[x][y] != word[t]) return false;
        if (word.size() == 1) return true;
		board[x][y] = '$';
		for (int z = 0; z < 4; ++z)
		{
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() &&
				calc(board, word, nx, ny, t + 1))
				return true;				
		}
		board[x][y] = word[t];
        return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty()) return false;
		int N = board.size(), M = board[0].size();
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				if (calc(board, word, i, j, 0))
					return true;
		return false;
	}
	vector<int>	dx{ 0, -1, 0, 1 };
	vector<int>	dy{ -1, 0, 1, 0 };
};