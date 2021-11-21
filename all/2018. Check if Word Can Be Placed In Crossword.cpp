class Solution {
public:
	bool placeWordInCrossword(vector<vector<char>>& board, string word) {
		int N = board.size(), M = board[0].size(), W = word.size();
		for (int z = 0; z < 2; ++z)
		{
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
				{
					if ((i == 0 || board[i - 1][j] == '#') && (i + W == N || i + W < N && board[i + W][j] == '#'))
					{
						bool isOk = true;
						for (int k = 0; isOk && k < W; ++k)
							isOk = board[i + k][j] == word[k] || board[i + k][j] == ' ';
						if (isOk)
							return true;
					}
					if ((j == 0 || board[i][j - 1] == '#') && (j + W == M || j + W < M && board[i][j + W] == '#'))
					{
						bool isOk = true;
						for (int k = 0; isOk && k < W; ++k)
							isOk = board[i][j + k] == word[k] || board[i][j + k] == ' ';
						if (isOk)
							return true;
					}
				}
			reverse(word.begin(), word.end());
		}
		return false;
	}
};