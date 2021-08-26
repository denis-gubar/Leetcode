class Solution {
public:
	const int MOD = 1'000'000'007;
	int ways(vector<string>& pizza, int k) {
		long long result = 0;
		int N = pizza.size(), M = pizza[0].size();
		vector<vector<int>> appleCount(N, vector<int>(M));
		for (int i = N - 1; i >= 0; --i)
		{
			int current = 0;
			for (int j = M - 1; j >= 0; --j)
			{
				appleCount[i][j] = (current += pizza[i][j] == 'A');
				if (i < N - 1)
					appleCount[i][j] += appleCount[i + 1][j];
			}
		}
		if (appleCount[0][0] == 0)
			return 0;
		--k;
		if (k == 0)
			return 1;
		auto f = [&appleCount](int i, int j, int deltaH, int deltaV)
		{
			int result = appleCount[i][j];
			if (deltaH)
				result -= appleCount[i + deltaH][j];
			else
				result -= appleCount[i][j + deltaV];
			return result;
		};
		vector<vector<vector<int>>> F(k + 1, vector<vector<int>>(N, vector<int>(M)));
		F[0][0][0] = 1;
		for (int z = 0; z < k; ++z)
			for(int i = 0; i < N; ++i)
				for(int j = 0; j < M; ++j)
					if (F[z][i][j])
					{
						for (int h = i + 1; h < N; ++h)
							if (appleCount[h][j] && f(i, j, h - i, 0))
							{
								F[z + 1][h][j] += F[z][i][j];
								F[z + 1][h][j] %= MOD;
							}
						for (int v = j + 1; v < M; ++v)
							if (appleCount[i][v] && f(i, j, 0, v - j))
							{
								F[z + 1][i][v] += F[z][i][j];
								F[z + 1][i][v] %= MOD;
							}
					}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				result += F[k][i][j];
		return result % MOD;
	}
};