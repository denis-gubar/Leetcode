class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		int result = 0;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; ++j)
				if (abs(nums[i] - nums[j]) == k)
					++result;
		return result;
	}
};