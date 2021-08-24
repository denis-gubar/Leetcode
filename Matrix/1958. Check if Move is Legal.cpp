class Solution {
public:
	bool checkMove(vector<vector<char>>& board, int x, int y, char color) {
		for(int dx = -1; dx <= 1; ++dx)
			for(int dy = -1; dy <= 1; ++dy)
				if (dx != 0 || dy != 0)
				{
					for (int length = 1, nx = x + dx, ny = y + dy; nx >= 0 && nx < 8 && ny >= 0 && ny < 8; ++length, nx += dx, ny += dy)
					{
						if (board[nx][ny] == '.')
							break;
						if (board[nx][ny] == color)
						{
							if (length > 1)
								return true;
							break;
						}
					}
				}
		return false;
	}
};