static int F[10'001];
static int M[10'001][101];
class Solution {
public:
	static const int MOD = 1'000'000'007;
	int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
		long long result = 0;
		int N = group.size();
		memset(M, 0, sizeof(M));
		memset(F, 0, sizeof(F));
		M[0][0] = 1;
		F[0] = 1;
		for (int k = 0; k < N; ++k)
		{
			for (int i = 10'000; i >= profit[k]; --i)
				if (F[i - profit[k]])
				{
					for (int j = n; j >= group[k]; --j)
					{
						M[i][j] += M[i - profit[k]][j - group[k]];
						M[i][j] %= MOD;
					}
					F[i] = 1;
				}
		}
		for (int i = minProfit; i <= 10'000; ++i)
			for (int j = 0; j <= n; ++j)
				result += M[i][j];
		return result % MOD;
	}
};