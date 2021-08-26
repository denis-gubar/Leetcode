class Solution {
public:
	int maxSubArrayLen(vector<int>& nums, int k) {
		int result = 0;
		int N = nums.size();
		vector<int> cum(N + 1);
		unordered_map<int, int> M;
		M[cum[0]] = 0;
		for (int i = 0; i < N; ++i)
		{
			cum[i + 1] = cum[i] + nums[i];
			M[cum[i + 1]] = i + 1;
		}
		for (int i = 0; i <= N; ++i)
		{
			int value = k + cum[i];
			if (M.find(value) != M.end())
				result = max({ result, M[value] - i });
		}
		return result;
	}
};