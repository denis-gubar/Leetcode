class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		int N = nums.size();
		if (N == 1)
			return 1;
		int a = min_element(nums.begin(), nums.end()) - nums.begin();
		int b = max_element(nums.begin(), nums.end()) - nums.begin();
		int result = max(a, b) + 1;
		result = min<int>(result, N - min(a, b));
		result = min<int>(result, min(a, b) + 1 + N - max(a, b));
		return result;
	}
};