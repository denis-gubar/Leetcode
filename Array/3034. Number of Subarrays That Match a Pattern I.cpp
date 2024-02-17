class Solution {
public:
	template <int base = 29>
	struct HashString
	{
		const int MOD = 1'000'000'007;
		HashString(vector<int> const& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
		{
			power[0] = 1;
			for (int i = 1; i <= N; ++i)
			{
				power[i] = 1LL * power[i - 1] * base % MOD;
				prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
			}
		}
		static int hash(int c)
		{
			return c + 1;
		}
		int hash(int start, int length) const
		{
			return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
		}
		int N;
		vector<int> prefixes;
		vector<int> power;
		vector<int> data;
	};
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = nums.size(), M = pattern.size();
        int result = 0;
        vector<int> A(N - 1);
        for (int i = 1; i < N; ++i)
            if (nums[i] > nums[i - 1])
                A[i - 1] = 1;
            else if (nums[i] < nums[i - 1])
                A[i - 1] = -1;
		HashString<11> P1(pattern);
		HashString<13> P2(pattern);
		HashString<11> A1(A);
		HashString<13> A2(A);
		for (int start = 0; start + M < N; ++start)
			if (A1.hash(start, M) == P1.hash(0, M) &&
				A2.hash(start, M) == P2.hash(0, M))
				++result;
		return result;
    }
};
