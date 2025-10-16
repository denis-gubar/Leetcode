class Solution {
public:
	vector<int> z_function(string const& s)
	{
		int N = s.size();
		vector<int> z(N);
		for (int i = 1, L = 0, R = 1; i < N; ++i)
		{
			if (i < R)
				z[i] = min(R - i, z[i - L]);
			while (i + z[i] < N && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] > R)
				L = i, R = i + z[i];
		}
		return z;
	}
	int minStartingIndex(string s, string pattern) {
		int const N = s.size(), P = pattern.size();
		string z = pattern + '#' + s;
		vector<int> Z = z_function(z);
		string r{ s };
		reverse(r.begin(), r.end());
		string p = pattern;
		reverse(p.begin(), p.end());
		r = p + '#' + r;
		vector<int> R = z_function(p + '#' + r);
		for (int i = P + 1, k = 0; k + P <= N; ++i, ++k)
		{
			if (Z[i] == P)
				return k;
			if (R[P + N - k + 2] + Z[i] + 1 >= P)
				return k;
		}
		return -1;
    }
};
