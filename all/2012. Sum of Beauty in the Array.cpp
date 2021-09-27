class Solution {
public:
	int sumOfBeauties(vector<int>& nums) {
		int N = nums.size();
		vector<int> A(N);
		int left = nums[0];
		int right = nums[N - 1];
		int result = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			right = min(right, nums[i]);
			A[i] = right;
		}
		for (int i = 1; i < N - 1; ++i)
		{
			if (left < nums[i] && nums[i] < A[i + 1])
				result += 2;
			else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
				++result;
			left = max(left, nums[i]);
		}
		return result;
	}
};