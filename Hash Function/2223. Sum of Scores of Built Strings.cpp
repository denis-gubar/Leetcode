class Solution {
public:
	vector<int> z_function(string const& s)
	{
		int n = s.length();
		vector<int> z(n);
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = min(r - i + 1, z[i - l]);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] - 1 > r)
				l = i, r = i + z[i] - 1;
		}
		return z;
	}
    long long sumScores(string s) {
		int N = s.size();
        long long result = N;
		vector<int> A = z_function(s);
		for (int x : A)
			result += x;
        return result;
    }
};
