class Solution {
public:
	int maximumDifference(vector<int>& nums) {
		int result = -1;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				if (nums[i] < nums[j])
					result = max(result, nums[j] - nums[i]);
		return result;
	}
};