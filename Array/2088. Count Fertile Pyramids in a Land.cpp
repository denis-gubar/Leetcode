class Solution {
public:
	int calc(vector<vector<int>>& grid)
	{
		int result = 0;
		int N = grid.size(), M = grid[0].size();
		vector<vector<int>> F(N, vector<int>(M, 0));
		for (int i = N - 2; i >= 0; --i)
			for(int j = 1; j < M - 1; ++j)
				if (grid[i][j] + grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] == 4)
				{
					F[i][j] = min({ F[i + 1][j - 1], F[i + 1][j], F[i + 1][j + 1] }) + 1;
					result += F[i][j];
				}
		return result;
	}
	int countPyramids(vector<vector<int>>& grid) {
		int result = calc(grid);
		reverse(grid.begin(), grid.end());
		result += calc(grid);
		return result;
	}
};