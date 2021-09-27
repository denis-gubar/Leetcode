class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		vector<unordered_map<long long, int>> M(N);
		for (int i = 1; i < N; ++i)
			for (int j = 0; j < i; ++j)
			{
				long long delta = 0LL + nums[i] - nums[j];
				int sum = M[j][delta];
				result += sum;
				M[i][delta] += sum + 1;
			}
		return result;
	}
};