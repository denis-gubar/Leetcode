class Solution {
public:
	int const MOD = 1'000'000'007;
	int calc(int n, int k)
	{
		if (n == 1 && k == 0)
			return 1;
		if (k < 0 || k > n * (n - 1) / 2)
			return 0;
		if (F[n][k] == -1)
			F[n][k] = (0LL + calc(n, k - 1) + calc(n - 1, k) - calc(n - 1, k - n) + MOD) % MOD;
		return F[n][k];
	}
	int kInversePairs(int n, int k) {
		F = vector<vector<int>>(1001, vector<int>(1001, -1));
		return calc(n, k);
	}
	vector<vector<int>> F;
};