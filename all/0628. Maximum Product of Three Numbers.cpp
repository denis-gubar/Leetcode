class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int N = nums.size();
		sort(nums.begin(), nums.end());
		int result = max({ nums[0] * nums[1] * nums[N - 1], nums[N - 3] * nums[N - 2] * nums[N - 1] });
		return result;
	}
};