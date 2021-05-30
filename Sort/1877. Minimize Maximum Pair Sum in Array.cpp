class Solution {
public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int N = nums.size();
		int result = 0;
		for (int a = 0, b = N - 1; a < b; ++a, --b)
			result = max(result, nums[a] + nums[b]);
		return result;
	}
};