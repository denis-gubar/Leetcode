class Solution {
public:
	template <int base>
	struct HashString
	{
		const int MOD = 1'000'000'007;
		HashString(const string& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
		{
			power[0] = 1;
			for (int i = 1; i <= N; ++i)
			{
				power[i] = 1LL * power[i - 1] * base % MOD;
				prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
			}
		}
		static int hash(char c)
		{
			return c - 'a' + 1;
		}
		int hash(int start, int length) const
		{
			return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
		}
		int N;
		vector<int> prefixes;
		vector<int> power;
		string data;
	};
	vector<int> calc(string const& s, string const& x)
	{
		vector<int> result;
		HashString<29> H1(s), X1(x);
		HashString<31> H2(s), X2(x);
		int N = s.size(), M = x.size();
		int hash1 = X1.hash(0, M);
		int hash2 = X2.hash(0, M);
		for (int i = 0; i + M <= N; ++i)
			if (H1.hash(i, M) == hash1 && H2.hash(i, M) == hash2)
				result.push_back(i);
		return result;
	}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
		vector<int> result;
		int N = s.size(), NA = a.size(), NB = b.size();
		vector<int> A = calc(s, a);
		vector<int> B = calc(s, b);
		for (int i : A)
		{
			auto it = lower_bound(B.begin(), B.end(), i - k);
			if (it != B.end() && abs(*it - i) <= k)
				result.push_back(i);
		}
		return result;
    }
};
