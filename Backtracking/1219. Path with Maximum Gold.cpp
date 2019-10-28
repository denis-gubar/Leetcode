class Solution {
public:
	vector<int> dx{ 0, 1, 0, -1 };
	vector<int> dy{ 1, 0, -1, 0 };
	void calc(vector<vector<int>>& M, vector<vector<int>> grid, int x, int y, int& current, int& result)
	{
		for (int z = 0; z < 4; ++z)
		{
			int nx = dx[z] + x;
			int ny = dy[z] + y;
			if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] && !M[nx][ny])
			{
				current += grid[nx][ny];
                result = max(result, current);
				M[nx][ny] = 1;
				calc(M, grid, nx, ny, current, result);
				M[nx][ny] = 0;
				current -= grid[nx][ny];
			}
		}
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		int result = 0;
		vector<pair<int, int>> goldPositions;
		vector<vector<int>> M(grid.size(), vector<int>(grid[0].size(), 0));
		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[0].size(); ++j)
				if (grid[i][j])
					goldPositions.push_back({ i, j });
		for (auto startPosition : goldPositions)
		{
			int const& x = startPosition.first;
			int const& y = startPosition.second;
			int current = grid[x][y];
			result = max(result, current);
			M[x][y] = 1;
			calc(M, grid, x, y, current, result);
            M[x][y] = 0;
		}
		return result;
	}
};