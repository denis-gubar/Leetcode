class Solution {
public:
	int const MOD = 1'000'000'007;
    vector<vector<int>> F;
	int f(int a, int b)
	{
		if (a > b)
			swap(a, b);
		if (F[a][b] < 0)
		{
			if (a == 0)
				F[a][b] = 1;
			else
				F[a][b] = (f(a, b - 1) + f(a - 1, b)) % MOD;
		}
		return F[a][b];
	}
	int calc(vector<int> const& nums)
	{
		if (nums.size() < 3)
			return 1;
		vector<int>	left, right;
		for (int i = 1; i < nums.size(); ++i)
			if (nums[i] < nums[0])
				left.push_back(nums[i]);
			else
				right.push_back(nums[i]);
		long long result = 1LL * f(left.size(), right.size()) * calc(left) % MOD;
        result *= calc(right);
		return result % MOD;
	}
	int numOfWays(vector<int>& nums) {
		int N = nums.size();
		F = vector<vector<int>>(N, vector<int>(N, -1));
		return (1'000'000'006 + calc(nums)) % MOD;
	}
};