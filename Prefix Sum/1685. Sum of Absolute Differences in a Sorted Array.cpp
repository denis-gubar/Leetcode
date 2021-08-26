class Solution {
public:
	vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
		int N = nums.size();
		vector<int> result(N);
		int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
		int prev = 0;
		for (int i = 0; i < N; ++i)
		{
			right -= (nums[i] - prev) * (N - i);
			if (i > 0)
				left += (nums[i] - prev) * i;
			result[i] = left + right;
			prev = nums[i];
		}
		return result;
	}
};