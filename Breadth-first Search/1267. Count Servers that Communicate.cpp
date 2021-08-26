class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int M = grid.size(), N = grid[0].size();
		int result = 0;
		for (int i = 0; i < M; ++i)
		{
			int count = 0;
			for (int j = 0; j < N; ++j)
				count += grid[i][j];
			if (count > 1)
				for (int j = 0; j < N; ++j)
					grid[i][j] *= 1001;
		}
		for (int j = 0; j < N; ++j)
		{
			int count = 0;
			for (int i = 0; i < M; ++i)
				count += grid[i][j];
			if (count % 1000 > 1)
				for (int i = 0; i < M; ++i)
					grid[i][j] = grid[i][j] ? 1001 : 0;
		}
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j)
				if (grid[i][j] > 1)
					++result;
		return result;
	}
};
