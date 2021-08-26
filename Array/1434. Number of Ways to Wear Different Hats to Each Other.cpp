class Solution {
public:
	const int MOD = 1'000'000'007;
	int numberWays(vector<vector<int>>& hats) {
		vector<vector<int>> H(41);
		int N = hats.size();
		for (int i = 0; i < N; ++i)
			for (int h : hats[i])
				H[h].push_back(i);
		vector<vector<int>> F(41, vector<int>(1 << N));
		F[0][0] = 1;
		for (int n = 0; n < 40; ++n)
		{
			F[n + 1] = F[n];
			for (int mask = 0; mask < (1 << N); ++mask)
				if (F[n][mask])
					for (int h : H[n + 1])
						if ((mask & (1 << h)) == 0)
						{
							F[n + 1][mask | (1 << h)] += F[n][mask];
							F[n + 1][mask | (1 << h)] %= MOD;
						}
		}
		return F[40].back();
	}
};