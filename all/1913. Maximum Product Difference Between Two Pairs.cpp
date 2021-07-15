class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int N = nums.size();
		return nums[N - 1] * nums[N - 2] - nums[0] * nums[1];
	}
};