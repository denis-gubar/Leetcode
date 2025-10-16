class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		long long result = 0;
		int N = nums.size();
		vector<long long> cum(N + 1);
		unordered_map<long long, int> M;
		M[cum[0]] = 0;
		for (int i = 0; i < N; ++i)
		{
			cum[i + 1] = cum[i] + nums[i];
			M[cum[i + 1]] = i + 1;
		}
		for (int i = 0; i <= N; ++i)
		{
			long long value = k + cum[i];
			if (M.find(value) != M.end())
				result = max<long long>(result, M[value] - i);
		}
		return result;
	}
};