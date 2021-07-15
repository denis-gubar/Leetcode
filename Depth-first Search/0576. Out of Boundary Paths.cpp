class Solution {
public:
	int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
		long long result = 0;
		int const MOD = 1'000'000'007;
		int F[2][53][53];
		memset(F, 0, sizeof(F));
		F[0][startRow + 1][startColumn + 1] = 1;
		for (int k = 0; k < maxMove; ++k)
		{
			auto& prev = F[k % 2];
			auto& next = F[(k + 1) % 2];
			memset(next, 0, sizeof(next));
			for(int x = 1; x <= m; ++x)
				for(int y = 1; y <= n; ++y)
					if (prev[x][y])
						for (int z = 0; z < 4; ++z)
						{
							int nx = x + dx[z];
							int ny = y + dy[z];
							next[nx][ny] += prev[x][y];
							if (next[nx][ny] >= MOD)
								next[nx][ny] -= MOD;
						}
            for (int i = 1; i <= m; ++i)
            {
                result += next[i][0];
                result += next[i][n + 1];
            }
            for (int j = 1; j <= n; ++j)
            {
                result += next[0][j];
                result += next[m + 1][j];
            }
		}
		return result % MOD;
	}
};