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
		long long hash(int start, int length) const
		{
			return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
		}
		int N;
		vector<int> prefixes;
		vector<int> power;
		string data;
	};
    int minimumOperationsToMakeKPeriodic(string word, int K) {
        int N = word.size();
        int result = N / K;
		HashString<29> H1(word);
		HashString<31> H2(word);
		unordered_map<long long, int> M;
		for (int i = 0; i < N; i += K)
			++M[(H1.hash(i, K) << 30) | H2.hash(i, K)];
		for (auto [key, value] : M)
			result = min(result, N / K - value);
		return result;
    }
};
