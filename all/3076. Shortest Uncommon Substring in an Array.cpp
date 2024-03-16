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
    vector<string> shortestSubstrings(vector<string>& arr) {
        int N = arr.size();
        vector<string> result(N);
		vector<string_view> A(N);
		vector<HashString<29>> H1;
		vector<HashString<31>> H2;
		H1.reserve(N);
		H2.reserve(N);
		for (string const& s : arr)
		{
			H1.push_back({ s });
			H2.push_back({ s });
		}
		vector<unordered_map<long long, bitset<100>>> M(21);
		for (int i = 0; i < N; ++i)
		{
			string const& s = arr[i];
			for (int K = s.size(), length = 1; length <= K; ++length)
				for (int start = 0; start + length <= K; ++start)
					M[length][(H1[i].hash(start, length) << 32) | H2[i].hash(start, length)][i] = true;
		}
		for (int i = 0; i < N; ++i)
		{
			string_view s{ arr[i] };
			bool flag = true;
			for (int K = s.size(), length = 1; flag && length <= K; ++length)
			{
				for (int start = 0; start + length <= K; ++start)
					if (M[length][(H1[i].hash(start, length) << 32) | H2[i].hash(start, length)].count() == 1)
					{
						if (A[i].empty() || s.substr(start, length) < A[i])
							A[i] = s.substr(start, length);
						flag = false;
					}
			}
		}
		for (int i = 0; i < N; ++i)
			result[i] = A[i];
		return result;
    }
};
