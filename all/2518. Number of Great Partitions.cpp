class Solution {
public:
	int const MOD = 1'000'000'007;
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
    int countPartitions(vector<int>& nums, int k) {
        int N = nums.size();
        int result = power(2, N);
		long long total = accumulate(nums.begin(), nums.end(), 0LL);
		if (total < 2 * k)
			return 0;
		vector<vector<int>> F(k, vector<int>(N + 1));
		F[0][0] = 1;
		for(int sum = 0; sum < k; ++sum)
			for(int i = 0; i < N; ++i)
				if (F[sum][i] > 0)
				{
					if (sum + nums[i] < k)
					{
						F[sum + nums[i]][i + 1] = (F[sum + nums[i]][i + 1] + F[sum][i]) % MOD;
					}
					F[sum][i + 1] = (F[sum][i + 1] + F[sum][i]) % MOD;
				}
		for (int sum = 0; sum < k; ++sum)
		{
			result -= 2 * F[sum][N];
			if (result < 0)
				result += 2 * MOD;
			result %= MOD;
		}
        return result;
    }
};
