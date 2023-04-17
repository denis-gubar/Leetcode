class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int N = nums.size();
		vector<bool> isPrime(1'001, true);
		isPrime[1] = isPrime[0] = false;
		for (int i = 2; i * i < 1'001; ++i)
			if (isPrime[i])
				for (int k = i * i; k < 1'001; k += i)
					isPrime[k] = false;
		vector<int> primes;
		for (int i = 2; i < 1'001; ++i)
			if (isPrime[i])
				primes.push_back(i);
		int prev = 0;
		for (int i = 0; i < N; ++i)
		{
			auto it = lower_bound(primes.begin(), primes.end(), nums[i] - prev);
			int x = nums[i];
			if (x - prev <= 0)
				return false;
			if (it != primes.begin())
			{
				--it;
				x = nums[i] - *it;
			}
			nums[i] = x;
			prev = nums[i];
		}
		return true;
    }
};
