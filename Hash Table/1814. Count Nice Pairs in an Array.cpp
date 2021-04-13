class Solution {
public:
	int const MOD = 1'000'000'007;	
	int calc(int x)
	{		
		return x - rev(x);
	}
	int rev(int x)
	{
		int result = 0;
		while (x > 0)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
		return result;
	}
	int countNicePairs(vector<int>& nums) {
		long long result = 0;
		int N = nums.size();
		unordered_map<int, int> H;
		for (int i = 0; i < N; ++i)
		{
			int const& x = nums[i];
			++H[calc(x)];
		}
		for (auto [key, count] : H)
			result += 1LL * count * (count - 1) / 2;
		return result % MOD;
	}
};