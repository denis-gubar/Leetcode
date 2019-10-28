class Solution {
public:
	int calc(string const& s, int start, int end)
	{
		if (start >= end) return 0;
		int result = F[start][end];
		if (result < 0)
		{
			if (s[start] == s[end])
				result = calc(s, start + 1, end - 1);
			else
				result = 1 + min(calc(s, start + 1, end), calc(s, start, end - 1));
		}
		return F[start][end] = result;
	}
	bool isValidPalindrome(string s, int k) {
		int N = s.size();
		F = vector<vector<int>>(N, vector<int>(N, -1));
		calc(s, 0, N - 1);
		return F[0][N - 1] <= k;
	}
	vector<vector<int>> F;
};