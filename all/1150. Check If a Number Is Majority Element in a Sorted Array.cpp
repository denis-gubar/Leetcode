class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		int count = 0;
		for (int n : nums)
			count += n == target;
		return count * 2 > nums.size();
	}
};