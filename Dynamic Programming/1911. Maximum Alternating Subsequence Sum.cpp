class Solution {
public:
	long long maxAlternatingSum(vector<int>& nums) {
		long long result = 0;
		int N = nums.size();
		vector<vector<long long>> F(2, vector<long long>(N + 1));
		for (int i = 0; i < N; ++i)
		{
			long long x = nums[i];
			F[1][i + 1] = max(F[1][i], F[0][i] + x);
			F[0][i + 1] = max(F[0][i], F[1][i] - x);
		}
		for (int i = 0; i <= N; ++i)
			result = max(result, F[1][i]);
		return result;
	}
};