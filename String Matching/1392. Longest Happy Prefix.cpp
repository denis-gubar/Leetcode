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
	string longestPrefix(string s) {
		HashString<29> H1(s);
		HashString<31> H2(s);
		int N = s.size();
		for (int length = N - 1; length > 0; --length)
			if (H1.hash(0, length) == H1.hash(N - length, length) &&
				H2.hash(0, length) == H2.hash(N - length, length) &&
				s.substr(0, length) == s.substr(N - length, length))
				return s.substr(0, length);
		return {};
	}
};