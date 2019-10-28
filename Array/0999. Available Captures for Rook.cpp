class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int result = 0;
		vector<int> dx{ 0, -1, 0, 1 };
		vector<int> dy{ -1, 0, 1, 0 };
		int rx = 0, ry = 0;
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 8; ++j)
				if (board[i][j] == 'R')
					rx = i, ry = j;
		for (int z = 0; z < 4; ++z)
		{
			int nx = rx, ny = ry;
			while (true)
			{
				nx += dx[z], ny += dy[z];
				if (nx < 0 || nx == 8 || ny < 0 || ny == 8 || board[nx][ny] == 'B')
					break;
				if (board[nx][ny] == 'p')
				{
					++result;
					break;
				}
			}
		}
		return result;
	}
};