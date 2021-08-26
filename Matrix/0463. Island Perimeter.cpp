class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		int result = 0;
		int N = grid.size(), M = grid[0].size();
		auto get = [&grid, N, M](int x, int y)
		{
			if (x >= 0 && x < N && y >= 0 && y < M)
				return grid[x][y];
			return 0;
		};
		for (int i = -1; i < N; ++i)
			for (int j = -1; j < M; ++j)
				result += (get(i, j) + get(i + 1, j) == 1) + (get(i, j) + get(i, j + 1) == 1);
		return result;
	}
};