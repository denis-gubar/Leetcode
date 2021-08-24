class Solution {
public:
	const int MOD = 1'000'000'007;
	int power(int x, long long n)
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
	int minNonZeroProduct(int p) {
		if (p == 1)
			return 1;
		long long result = ((1LL << p) - 1) % MOD;
		long long n = (1LL << (p - 1)) - 1;
		int x = ((1LL << p) - 2) % MOD;
		result *= power(x, n);
		return result % MOD;
	}
};