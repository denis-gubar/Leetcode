class Solution {
public:
	static const int MOD = 1000000007;
	int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
		long long result = 0;
		int N = group.size();
		vector<vector<int>> M(10001, vector<int>(G + 1));
		vector<int> F(10001, 0);
		M[0][0] = 1;
		F[0] = 1;
		for (int k = 0; k < N; ++k)
		{
			for (int i = 10000; i >= profit[k]; --i)
				if (F[i - profit[k]])
				{
					for (int j = G; j >= group[k]; --j)
					{
						M[i][j] += M[i - profit[k]][j - group[k]];
						M[i][j] %= MOD;
					}
					F[i] = 1;
				}
		}
		for (int i = P; i <= 10000; ++i)
			for (int j = 0; j <= G; ++j)
				result += M[i][j];
		return result % MOD;
	}
};