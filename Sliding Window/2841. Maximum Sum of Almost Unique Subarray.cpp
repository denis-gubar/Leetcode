class Solution {
public:
	long long maxSum(vector<int>& nums, int M, int K) {
		int N = nums.size();
		long long result = 0;
		unordered_map<int, int> counts;
		int distinctCount = 0;
		long long balance = 0;
		for (int i = 0; i < K; ++i)
		{
			int x = ++counts[nums[i]];
			if (x == 1)
				++distinctCount;
			balance += nums[i];
		}
		if (distinctCount >= M)
			result = max(result, balance);
		for (int i = K; i < N; ++i)
		{
			balance += nums[i];
			int x = ++counts[nums[i]];
			if (x == 1)
				++distinctCount;
			balance -= nums[i - K];
			x = --counts[nums[i - K]];
			if (x == 0)
				--distinctCount;
			if (distinctCount >= M)
				result = max(result, balance);
		}
		return result;
	}
};
