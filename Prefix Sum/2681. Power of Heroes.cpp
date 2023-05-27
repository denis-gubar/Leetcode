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

    int sumOfPower(vector<int>& nums) {
        int N = nums.size();
		sort(nums.begin(), nums.end());
		long long result = power(nums[0], 3);
		long long current = nums[0];
        for (int i = 1; i < N; ++i)
        {
			long long delta = 1LL * nums[i] * nums[i] % MOD * current % MOD;
			result = (result + delta + power(nums[i], 3)) % MOD;
			current = (current * 2 + nums[i]) % MOD;
        }
        return result % MOD;
    }
};
