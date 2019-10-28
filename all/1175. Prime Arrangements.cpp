class Solution {
public:
	static const int MOD = 1000000007;
	int numPrimeArrangements(int n) {
		vector<long long> F(101);
		F[0] = 1;
		for (int i = 1; i < 101; ++i)
			F[i] = F[i - 1] * i % MOD;
		vector<bool> isPrime(101, true);
		isPrime[1] = isPrime[0] = false;
		for (int i = 2; i * i < 101; ++i)
			if (isPrime[i])
				for (int k = i * i; k < 101; k += i)
					isPrime[k] = false;
		vector<int> primes;
		for (int i = 2; i < 101; ++i)
			if (isPrime[i])
				primes.push_back(i);
		int k = lower_bound(primes.begin(), primes.end(), n + 1) - primes.begin();
		return F[k] * F[n - k] % MOD;
	}
};
