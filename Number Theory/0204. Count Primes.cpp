class Solution {
public:
	int countPrimes(int n) {
        if (n < 3)
            return 0;
		vector<bool> isPrime(n, true);
		isPrime[1] = isPrime[0] = false;
		for (int i = 2; i * i < n; ++i)
			if (isPrime[i])
				for (int k = i * i; k < n; k += i)
					isPrime[k] = false;
		int result = 0;
		for (int i = 2; i < n; ++i)
			if (isPrime[i])
				++result;
		return result;
	}
};