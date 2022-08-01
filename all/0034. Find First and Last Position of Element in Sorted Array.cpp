class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto p = equal_range(nums.begin(), nums.end(), target);
		if (p.first == p.second)
			return { -1, -1 };
		return { static_cast<int>(p.first - nums.begin()), static_cast<int>(p.second - nums.begin()) - 1 };
	}
};