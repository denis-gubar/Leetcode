class Solution {
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		vector<long long> A, B{ 0LL };
		int MOD = 1'000'000'007;
		A.reserve(n * (n + 1) / 2);
        B.reserve(n * (n + 1) / 2);
		for (int a = 0; a < n; ++a)
			for (int b = a, sum = 0; b < n; ++b)
				A.push_back(sum += nums[b]);
		sort(A.begin(), A.end());
		partial_sum(A.begin(), A.end(), back_inserter(B));
		return (B[right] - B[left - 1]) % MOD;
	}
};