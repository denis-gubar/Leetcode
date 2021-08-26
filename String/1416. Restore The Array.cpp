class Solution {
public:
	int const MOD = 1'000'000'007;
	bool check(string const& s, int start, int length, int k)
	{
		return start + length <= s.size() && s[start] != '0' && stoll(s.substr(start, length)) <= k;
	}
	int numberOfArrays(string s, int k) {
		int N = s.size();
		string x = to_string(k);
		int K = x.size();
		vector<int> F(N + 20);
        F[0] = 1;
		for (int start = 0; start < N; ++start)
        {
			for (int length = K; length > 0; --length)
				if (F[start] && check(s, start, length, k))
				{
					F[start + length] += F[start];
					F[start + length] %= MOD;
				}
        }
		return F[N];
	}
};