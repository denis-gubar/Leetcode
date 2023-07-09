class Solution {
public:
	const int MOD = 1'000'000'007;

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
	int monkeyMove(int n) {
		return (power(2, n) + (MOD - 2)) % MOD;
    }
};
