class Solution {
public:
	string longestPalindrome(string s) {
		string result = s.substr(0, 1);
		string p = "^";
		for (char c : s)
			p += '#', p += c;
		p += "#$";
		int N = p.size();
		vector<int> LPS(N);
		LPS[2] = 1;
		int C = 2, R = 3;
		for (int i = 3; i < N; ++i)
		{
			int iMirror = 2 * C - i;
			int diff = R - i;
			if (diff > 0)
				LPS[i] = min(LPS[iMirror], diff);
			while (p[i - LPS[i] - 1] == p[i + LPS[i] + 1])
				++LPS[i];
			if (result.size() < LPS[i])
				result = s.substr((i - LPS[i]) / 2, LPS[i]);
			if (i + LPS[i] > R)
				R = i + LPS[i], C = i;
		}
		return result;
	}
};