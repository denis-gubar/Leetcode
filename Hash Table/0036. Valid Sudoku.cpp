class Solution {
public:
	bool check(string line)
	{
		sort(line.begin(), line.end());
		if (unique(line.begin(), line.end()) != line.end())
			return false;
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i)
		{
			string line;
			for (int j = 0; j < 9; ++j)
				if (board[i][j] != '.')
					line += board[i][j];
			if (!check(line))
				return false;
		}
		for (int i = 0; i < 9; ++i)
		{
			string line;
			for (int j = 0; j < 9; ++j)
				if (board[j][i] != '.')
					line += board[j][i];
			if (!check(line))
				return false;
		}
		for(int startI = 0; startI < 9; startI += 3)
			for (int startJ = 0; startJ < 9; startJ += 3)
			{
				string line;
				for(int i = startI; i - startI < 3; ++i)
					for (int j = startJ; j - startJ < 3; ++j)
						if (board[i][j] != '.')
							line += board[i][j];
				if (!check(line))
					return false;
			}
		return true;
	}
};