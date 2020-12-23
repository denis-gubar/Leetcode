class Solution {
public:
	int const MOD = 1'000'000'007;
	int numWays(vector<string>& words, string target) {
		int W = words.size(), N = words[0].size(), M = target.size();
		vector<vector<pair<int, int>>> pos(26);
		vector<int> ind(26);
		for (int j = 0; j < N; ++j)
			for (int i = 0; i < W; ++i)
			{
				int x = words[i][j] - 'a';
				if (pos[x].empty() || pos[x].back().first != j)
					pos[x].push_back({ j, 1 });
				else
					++pos[x].back().second;
			}
		for (int i = 0; i < 26; ++i)
			pos[i].push_back({ N, 1 });
		vector<vector<int>> F(M + 1, vector<int>(N + 1));
		F[0][0] = 1;
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < M; ++i)
				if (F[i][j])
				{
					int x = target[i] - 'a';
					while (pos[x][ind[x]].first < j)
						++ind[x];
					for (int z = ind[x], k = pos[x][z].first; N - k >= M - i; ++z, k = pos[x][z].first)
						F[i + 1][k + 1] = (F[i + 1][k + 1] + 1LL * pos[x][z].second * F[i][j]) % MOD;
				}
		}
		long long result = 0;
		for (int j = 0; j <= N; ++j)
			result += F[M][j];
		return result % MOD;
	}
};