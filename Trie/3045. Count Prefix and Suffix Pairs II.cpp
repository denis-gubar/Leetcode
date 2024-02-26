static int Z[100'000];
class Solution {
public:
	void z_function(string_view s) {
		int N = s.size();
        memset(Z, 0, N * sizeof(int));
		for (int i = 1, l = 0, r = 0; i < N; ++i) {
			if (i <= r)
				Z[i] = min(r - i + 1, Z[i - l]);
			while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]])
				++Z[i];
			if (i + Z[i] - 1 > r)
				l = i, r = i + Z[i] - 1;
		}
	}
	template <int base = 29>
	struct HashString
	{
		const int MOD = 1'000'000'007;
		HashString(string_view s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
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
		long long hash(int start, int length) const
		{
			return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
		}
		int N;
		vector<int> prefixes;
		vector<int> power;
		string_view data;
	};
	long long countPrefixSuffixPairs(vector<string>& words) {
        long long result = 0;
		int N = words.size();
		unordered_map<int, unordered_map<long long, int>> H;
		for(int j = N - 1; j >= 0; --j)
		{
            string_view s{ words[j] };
			int K = s.size();
			HashString<29> H1(s);
			HashString<31> H2(s);
			long long key = (H1.hash(0, K) << 32LL) | H2.hash(0, K);
			if (auto it = H[K].find(key); it != H[K].end())
				result += it->second;
			z_function(s);
            for (int i = 1, length = K - 1; length > 0; ++i, --length)
				if (Z[i] == length)
				{
					long long key = (H1.hash(i, length) << 32LL) | H2.hash(i, length);
					++H[length][key];
				}
			++H[K][key];
		}
        return result;
    }
};
