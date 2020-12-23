class Solution {
public:
	int calc(vector<int> const& nums, int start, int end)
	{
        if (start > end)
            return 0;
		if (F[start][end] < 0)
		{
			int result = 0;
			for (int m = start; m <= end; ++m)
				result = max(result, nums[start - 1] * nums[m] * nums[end + 1] +
					calc(nums, start, m - 1) + calc(nums, m + 1, end));
			F[start][end] = result;
		}
		return F[start][end];
	}
	int maxCoins(vector<int>& nums) {
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		F = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
		return calc(nums, 1, static_cast<int>(nums.size()) - 2);
	}
	vector<vector<int>> F;
};