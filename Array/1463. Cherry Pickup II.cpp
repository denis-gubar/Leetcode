class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int N = grid.size(), M = grid[0].size();
		int result = 0;
		vector<vector<vector<int>>> F(2, vector<vector<int>>(M, vector<int>(M)));
		F[1][0][M - 1] = grid[0][0] + grid[0][M - 1] + 1;
		for (int i = 1; i < N; ++i)
		{
			F[(i + 1) % 2] = vector<vector<int>>(M, vector<int>(M));
			for (int a = 0; a < M; ++a)
				for (int b = 0; b < M; ++b)
					if (F[i % 2][a][b])
						for (int da = -1; da <= 1; ++da)
							if (da + a >= 0 && da + a < M)
								for (int db = -1; db <= 1; ++db)
									if (db + b >= 0 && db + b < M)
									{
										if (da + a == db + b)
											F[(i + 1) % 2][da + a][db + b] = max(F[(i + 1) % 2][da + a][db + b],
												F[i % 2][a][b] + grid[i][da + a]);
										else
											F[(i + 1) % 2][da + a][db + b] = max(F[(i + 1) % 2][da + a][db + b],
												F[i % 2][a][b] + grid[i][da + a] + grid[i][db + b]);
									}
		}
		for (int a = 0; a < M; ++a)
			for (int b = 0; b < M; ++b)
				result = max(result, F[N % 2][a][b]);
		return result - 1;
	}
};