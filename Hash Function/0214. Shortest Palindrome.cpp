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
    string shortestPalindrome(string s) {
		int N = s.size();
		string t = s + '#' + string(s.rbegin(), s.rend());
		vector<int> Z = z_function(t);
		int prefixLength = 0;
		for (int i = N + 1; i <= 2 * N; ++i)
			if (Z[i] == 2 * N - i + 1)
				prefixLength = max(prefixLength, Z[i]);
		return string(s.rbegin(), s.rbegin() + N - prefixLength) + s;
    }
};
