class Solution {
public:
	int dieSimulator(int n, vector<int>& rollMax) {
		const int MOD = 1000000007;
		vector<vector<int>> F(7);
		F[0] = { 1 };
		for (int i = 1; i < 7; ++i)
			F[i] = vector<int>(rollMax[i - 1] + 1);
		for (int t = 0; t < n; ++t)
		{
			vector<vector<int>> NF(F);
			for (vector<int>& row : NF)
				for (int& x : row)
					x = 0;
			for (int i = 1; i < 7; ++i)
			{
                for (int k = 0; k < 7; ++k)
                    if (k != i)
        				for (int j = 0; j < F[k].size(); ++j)
						{
							NF[i][1] += F[k][j];
							NF[i][1] %= MOD;
						}
				for (int j = 2; j < F[i].size(); ++j)
				{
					NF[i][j] += F[i][j - 1];
					NF[i][j] %= MOD;
				}
			}
			F = move(NF);
		}
		long long result = 0;
		for (int i = 1; i < 7; ++i)
			for (int j : F[i])
				result += j;
		return result % MOD;
	}
};