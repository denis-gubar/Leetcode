class Solution {
public:
	const int MOD = 1000000007;

	int power(int x, int n)
	{
		if (n == 1)
			return x;
		long long result = x;
		long long extra = 1;
		while (n > 1)
		{
			if (n % 2)
			{
				extra *= result;
				extra %= MOD;
			}
			result *= result;
			result %= MOD;
			n /= 2;
		}
		return result * extra % MOD;
	}


	int div(int x)
	{
		return power(x, MOD - 2);
	}
	int numberOfWays(int num_people) {
		int n = num_people / 2;
		vector<int> F(2 * n + 1);
		F[0] = 1;
		for (int i = 1; i < F.size(); ++i)
			F[i] = 1LL * F[i - 1] * i % MOD;
		return 1LL * F[2 * n] * div(F[n]) % MOD * div(F[n + 1]) % MOD;
	}
};