class Solution {
public:
	template <int base = 29>
	struct HashString
	{
		static int const MOD = 1'000'000'007;
		HashString(string const& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
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
    int longestRepeatingSubstring(string s) {
		int const N = s.size();
		HashString<29> H1(s);
		HashString<31> H2(s);
		for (int length = N - 1; length > 0; --length)
		{
			unordered_set<int> S1, S2;
			for (int start = 0; start + length <= N; ++start)
			{
				bool isInserted1 = S1.insert(H1.hash(start, length)).second;
				bool isInserted2 = S2.insert(H2.hash(start, length)).second;
				if (!isInserted1 && !isInserted2)
					return length;
			}
		}
		return 0;
    }
};
