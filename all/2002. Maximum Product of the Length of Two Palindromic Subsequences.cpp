class Solution {
public:
	int maxPalindrome(string const& s)
	{
		int N = s.size();
		vector<vector<int>> P(N, vector<int>(N));
		for (int i = 0; i < N; ++i)
			P[i][i] = 1;
		for (int length = 2; length <= N; ++length)
			for (int i = 0; i < N - length + 1; ++i)
			{
				int j = i + length - 1;
				if (s[i] == s[j] && length == 2)
					P[i][j] = 2;
				else if (s[i] == s[j])
					P[i][j] = P[i + 1][j - 1] + 2;
				else
					P[i][j] = max(P[i][j - 1], P[i + 1][j]);
			}
		return P[0][N - 1];
	}
	int maxProduct(string s) {
		int N = s.size();
		int result = 1;
		for (int mask = 1; mask < (1 << N) - 1; ++mask)
		{
			string a, b;
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					a += s[k];
				else
					b += s[k];
			result = max(result, maxPalindrome(a) * maxPalindrome(b));
		}
		return result;
	}
};