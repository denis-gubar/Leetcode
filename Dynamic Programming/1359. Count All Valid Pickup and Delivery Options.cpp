class Solution {
public:
	static const int MOD = 1000000007;
	int countOrders(int n) {
		vector<long long> F(n + 1);
		F[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= 2 * i; ++j)
				F[i] = F[i] + (2 * i + 1 - j);

			F[i] = 1LL * F[i - 1] * F[i] % MOD;
		}
		return F[n - 1];
	}
};