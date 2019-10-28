class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<vector<int>> result;
		vector<vector<int>> grid(8, vector<int>(8));
		for (vector<int>& pos : queens)
			grid[pos[0]][pos[1]] = 1;
		int& x = king[0];
		int& y = king[1];
		for(int dx = -1; dx <= 1; ++dx)
			for(int dy = -1; dy <= 1; ++dy)
				if (dx || dy)
				{
					bool flag = true;
					for (int k = 1; flag && k < 7; ++k)
					{
						int nx = x + k * dx;
						int ny = y + k * dy;
						flag = nx >= 0 && nx < 8 && ny >= 0 && ny < 8;
						if (flag && grid[nx][ny])
						{
							result.push_back({ nx, ny });
							flag = false;
						}
					}
				}
		return result;
	}
};