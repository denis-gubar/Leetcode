class Solution {
public:
	template <int base=29>
	struct HashString
	{
		static int const MOD = 1'000'000'007;
		HashString(string const& s) : data(s), N(s.size()), 
			prefixes(vector<int>(N + 1)), power(prefixes), suffixes(prefixes)
		{
			power[0] = 1;
			for (int i = 1; i <= N; ++i)
			{
				power[i] = 1LL * power[i - 1] * base % MOD;
				prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
				suffixes[N - i] = (1LL * suffixes[N - i + 1] * base + hash(s[N - i])) % MOD;
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
		long long hashX(int pos) const
		{
			return ((1LL * prefixes[pos]) << 32) |
				suffixes[pos + 1];
		}
		int N;
		vector<int> prefixes;
		vector<int> suffixes;
		vector<int> power;
		string data;
	};
    bool differByOne(vector<string>& dict) {
		int N = dict.size(), M = dict[0].size();
		vector<HashString<29>> HS1;
		vector<HashString<31>> HS2;
		HS1.reserve(N); HS2.reserve(N);
		for (int i = 0; i < N; ++i)
		{
			HS1.emplace_back(dict[i]);
			HS2.emplace_back(dict[i]);
		}
		vector<unordered_set<long long>> S1(M), S2(M);
		for (int j = 0; j < M; ++j)
			for (int i = 0; i < N; ++i)
				if (!S1[j].insert(HS1[i].hashX(j)).second & !S2[j].insert(HS2[i].hashX(j)).second)
					return true;
		return false;
    }
};