class Solution {
public:
	int const MOD = 1000000007;
	int power(int x, long long n)
	{
		if (n == 0)
			return 1;
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
	int countGoodNumbers(long long n) {
		int x = 5 * 4;
		long long result = power(x, n / 2);
		if (n % 2 == 1)
		{
			result *= 5;
			result %= MOD;
		}
		return result;
	}
};