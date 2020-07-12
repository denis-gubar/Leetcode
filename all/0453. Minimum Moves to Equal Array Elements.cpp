class Solution {
public:
	int minMoves(vector<int>& nums) {
		int result = 0;
		int m = *min_element(nums.begin(), nums.end());
		for (int n : nums)
			result += n - m;
		return result;
	}
};