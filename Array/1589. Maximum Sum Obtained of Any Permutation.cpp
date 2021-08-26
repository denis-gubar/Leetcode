class Solution {
public:
	int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
		int const MOD = 1'000'000'007;
		int N = nums.size();
		vector<int>	A(N + 1), P(N);		
		for (int i = 0; i < requests.size(); ++i)
		{
			int const& begin = requests[i][0];
			int const& end = requests[i][1];			
			++A[begin];
			--A[end + 1];
		}
		for (int i = 0, sum = 0; i < N; ++i)
		{
			sum += A[i];
			P[i] = sum;
		}
		sort(P.begin(), P.end());
		sort(nums.begin(), nums.end());
		long long result = 0;
		for (int i = 0; i < N; ++i)
			result += 1LL * P[i] * nums[i];
		return result % MOD;
	}
};