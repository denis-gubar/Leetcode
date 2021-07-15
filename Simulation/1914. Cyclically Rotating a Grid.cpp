class Solution {
public:
	vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
		vector<vector<int>> result(grid);
		int N = grid.size(), M = grid[0].size();		
		for (int total = N * M, level = 0; total > 0; ++level)
		{
			vector<int> buffer;
			for (int x = level, y = level; y + level <= M - 1; ++y)
				buffer.push_back(grid[x][y]);
			for (int x = level + 1, y = M - 1 - level; x + level <= N - 1; ++x)
				buffer.push_back(grid[x][y]);
			for (int x = N - 1 - level, y = M - 1 - level - 1; y >= level; --y)
				buffer.push_back(grid[x][y]);
			for (int x = N - 1 - level - 1, y = level; x >= level + 1; --x)
				buffer.push_back(grid[x][y]);
			int B = buffer.size();
			total -= B;
			int K = k % B;
			if (K)
			{
				rotate(buffer.begin(), buffer.begin() + K, buffer.end());
				reverse(buffer.begin(), buffer.end());
				for (int x = level, y = level; y + level <= M - 1; ++y)
				{
					result[x][y] = buffer.back();
					buffer.pop_back();
				}
				for (int x = level + 1, y = M - 1 - level; x + level <= N - 1; ++x)
				{
					result[x][y] = buffer.back();
					buffer.pop_back();
				}
				for (int x = N - 1 - level, y = M - 1 - level - 1; y >= level; --y)
				{
					result[x][y] = buffer.back();
					buffer.pop_back();
				}
				for (int x = N - 1 - level - 1, y = level; x >= level + 1; --x)
				{
					result[x][y] = buffer.back();
					buffer.pop_back();
				}
			}
		}
		return result;
	}
};