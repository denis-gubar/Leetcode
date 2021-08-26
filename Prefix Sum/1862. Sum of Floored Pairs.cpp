class Solution {
public:
	int sumOfFlooredPairs(vector<int>& nums) {
		int const MOD = 1'000'000'007;
		vector<int> A(100'001);
		for (int x : nums)
			++A[x];
		vector<int> P{ 0 };
		long long result = 0;
		partial_sum(A.begin(), A.end(), back_inserter(P));
		for(int k = 1; k <= 100'000; ++k)
			if (A[k])
			{
				result += 1LL * A[k] * A[k];
				for (int m = 2; (m - 1) * k <= 100'000; ++m)
				{
					int a = max(k + 1, (m - 1) * k);
					int b = min(m * k - 1, 100'000);
				    result += 1LL * A[k] * (m - 1) * (P[b + 1] - P[a]);
				}
			}
		return result % MOD;
	}
};