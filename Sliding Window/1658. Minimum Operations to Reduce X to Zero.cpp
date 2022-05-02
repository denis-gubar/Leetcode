class Solution {
public:
	int minOperations(vector<int>& nums, int x) {
		int N = nums.size();
		vector<int>	A{ 0 };
		partial_sum(nums.begin(), nums.end(), back_inserter(A));
		int sum = 0;
		int result = N + 1;
		for (int t = 0; t <= N; ++t)
		{
			if (t)
				sum += nums[N - t];
			auto it = lower_bound(A.begin(), A.end(), x - sum);
			if (it != A.end() && *it == x - sum)
				result = min<int>(result, t + (it - A.begin()));
		}
		if (result == N + 1)
			result = -1;
		return result;
	}
};