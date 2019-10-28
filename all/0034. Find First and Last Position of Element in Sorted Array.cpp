class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto it = lower_bound(nums.begin(), nums.end(), target);
		if (it == nums.end() || *it != target)
			return { -1, -1 };
		return { it - nums.begin(), upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1 };
	}
};