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

    int countWays(vector<vector<int>>& ranges) {
        int N = ranges.size();
        int K = 0;
        int x = -1;
        sort(ranges.begin(), ranges.end());
        for (int i = 0; i < N; ++i)
        {
            if (x < ranges[i][0])
                ++K;
            x = max(x, ranges[i][1]);
        }
        return power(2, K);
    }
};
