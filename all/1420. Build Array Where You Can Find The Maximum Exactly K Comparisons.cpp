class Solution {
public:
	int const MOD = 1'000'000'007;
	int numOfArrays(int n, int m, int k) {
		if (k > m) return 0;
		vector<vector<vector<long long>>> F(n + 1, vector<vector<long long>>(k + 2, vector<long long>(m + 1)));
		for (int j = 1; j <= m; ++j)
			F[1][1][j] = 1;
		for (int i = 1; i < n; ++i)
			for (int j = 1; j <= k && j <= i; ++j)
				for(int z = 1; z <= m; ++z)
					for (int nz = z; nz <= m; ++nz)
					{
						if (nz > z)
						{
							F[i + 1][j + 1][nz] += F[i][j][z];
							F[i + 1][j + 1][nz] %= MOD;
						}
						else
						{
							F[i + 1][j][z] += z * F[i][j][z];
							F[i + 1][j][z] %= MOD;
						}
					}
		return accumulate(F[n][k].begin(), F[n][k].end(), 0LL) % MOD;
	}
};