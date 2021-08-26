class Solution {
public:
	int const MOD = 1'000'000'007;
	int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
		long long total = 0;
		int N = nums1.size();
		vector<int>	A(nums1.begin(), nums1.end());
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		for (int i = 0; i < N; ++i)
			total += abs(nums1[i] - nums2[i]);
        long long result = total;
		for (int i = 0; i < N; ++i)
		{
			int const& x = nums1[i];
			int const& y = nums2[i];
			long long best = abs(x - y);
			auto it = lower_bound(A.begin(), A.end(), y);
			if (it != A.end())
				best = min<long long>(best, abs(*it - y));
			if (it != A.begin())
			{
				--it;
				best = min<long long>(best, abs(*it - y));
			}
			result = min(result, total - abs(x - y) + best);
		}
		return result % MOD;
	}
};