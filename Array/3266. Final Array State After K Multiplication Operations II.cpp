static int const MOD = 1'000'000'007;
static int power(int x, int n)
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
class Solution {
public:
    vector<int> getFinalState(vector<int> nums, int k, int multiplier) {
        if (multiplier == 1)
            return nums;
        int const N = nums.size();
		set<pair<long long, int>> S;
		for (int i = 0; i < N; ++i)
			S.insert({ nums[i], i });
		long long M = prev(S.end())->first;
		long long MAX = 1LL * MOD * MOD;
		auto go = [&S, &nums, multiplier, MAX]
			{
				auto P = *S.begin();
				S.erase(S.begin());
				nums[P.second] = 1LL * nums[P.second] * multiplier % MOD;
				if (1.0 * P.first * multiplier < MAX)
					S.insert({ P.first * multiplier, P.second });
				else
					S.insert({ MAX, P.second });
			};
		for (; k > 0 && S.begin()->first <= M; --k)
			go();
		int X = power(multiplier, k / N);
		k %= N;
		for (; k > 0; --k)
			go();
		for (int& Z : nums)
			Z = 1LL * Z * X % MOD;
        return nums;
    }
};
