class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int N = nums.size() - 1;
		int noDuplicatesTotal = N * (N + 1) / 2;
		int result = -noDuplicatesTotal;
		for (int n : nums)
			result += n;
		return result;
	}
};