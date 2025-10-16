class Solution {
public:
	int const MOD = 1'000'000'007;
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
	int maxNiceDivisors(int primeFactors) {
		int x = primeFactors / 3;
		long long result = primeFactors;
        if (primeFactors > 3)
        {
            if (primeFactors % 3 == 0)
                result = power(3, primeFactors / 3);
            if (primeFactors % 3 == 1)
                result = power(3, primeFactors / 3 - 1) * 4LL % MOD;
            if (primeFactors % 3 == 2)
                result = power(3, primeFactors / 3) * 2LL % MOD;
        }
		return result;
	}
};