class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int N = nums.size();
		vector<int> result(N);
		result[0] = 1;
		for (int i = 1; i < N; ++i)
			result[i] = result[i - 1] * nums[i - 1];
		int suffix = 1;
		for (int i = N - 2; i >= 0; --i)
		{
			suffix *= nums[i + 1];
			result[i] *= suffix;
		}
		return result;
	}
};