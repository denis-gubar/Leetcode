class Solution {
public:
	int minimumDifference(vector<int>& nums, int k) {
		int result = 1 << 20;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int start = 0; start + k <= N; ++start)
			result = min(result, nums[start + k - 1] - nums[start]);
		return result;
	}
};