static int const MOD = 1'000'000'007;
class Solution {
public:
	int power(int x, int n)
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
	int div(int x)
	{
		return power(x, MOD - 2);
	}
    int sumOfNumbers(int L, int R, int K) {
		int const N = R - L + 1;
		long long result = power(N, K - 1);
		int sum = 0;
		for (int i = L; i <= R; ++i)
			sum += i;
		result = result * sum % MOD;
		long long base = power(10, K);
		base = (base + (MOD - 1)) % MOD;
        return base * div(9) % MOD * result % MOD;
    }
};
