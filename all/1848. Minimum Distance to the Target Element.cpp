class Solution {
public:
	int getMinDistance(vector<int>& nums, int target, int start) {
		int N = nums.size();
		int result = N;
		for (int i = 0; i < N; ++i)
			if (nums[i] == target)
				result = min(result, abs(i - start));
		return result;
	}
};