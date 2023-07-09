class Solution {
public:
	vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<vector<int>> result;
		nums.insert(nums.begin(), lower - 1LL);
		int N = nums.size();
		nums.push_back(upper + 1LL);
		for (int i = 0; i < N; ++i)
			if (nums[i + 1] - nums[i] == 2)
				result.push_back({nums[i] + 1, nums[i] + 1});
			else if (nums[i + 1] - nums[i] > 2)
				result.push_back({nums[i] + 1, nums[i + 1] - 1});
		return result;
	}
};