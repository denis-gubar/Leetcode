class Solution {
public:
	int maxProductPath(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		vector<vector<long long>> pos(N, vector<long long>(M, -1)), neg(N, vector<long long>(M, 1));
		if (grid[0][0] >= 0)
			pos[0][0] = grid[0][0];
		else
			neg[0][0] = grid[0][0];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				int x = grid[i][j];
				if (x >= 0)
				{
					if (i)
					{
						pos[i][j] = max(pos[i][j], pos[i - 1][j] * x);
						neg[i][j] = min(neg[i][j], neg[i - 1][j] * x);
					}
					if (j)
					{
						pos[i][j] = max(pos[i][j], pos[i][j - 1] * x);
						neg[i][j] = min(neg[i][j], neg[i][j - 1] * x);
					}
				}
				else
				{
					if (i)
					{
						pos[i][j] = max(pos[i][j], neg[i - 1][j] * x);
						neg[i][j] = min(neg[i][j], pos[i - 1][j] * x);
					}
					if (j)
					{
						pos[i][j] = max(pos[i][j], neg[i][j - 1] * x);
						neg[i][j] = min(neg[i][j], pos[i][j - 1] * x);
					}
				}
			}
		if (pos.back().back() == -1)
			return -1;
		return pos.back().back() % 1'000'000'007;
	}
};