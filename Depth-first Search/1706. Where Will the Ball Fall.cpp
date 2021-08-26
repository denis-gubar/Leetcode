class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<int> result;
		for (int i = 0; i < M; ++i)
		{
			int x = i;
			for (int y = 0; y < N; ++y)
				if (grid[y][x] == 1)
				{
					if (x + 1 == M || grid[y][x + 1] == -1)
					{
						x = -1;
						break;
					}
					++x;
				}
				else
				{
					if (x == 0 || grid[y][x - 1] == 1)
					{
						x = -1;
						break;
					}
					--x;
				}
			result.push_back(x);
		}
		return result;
	}
};