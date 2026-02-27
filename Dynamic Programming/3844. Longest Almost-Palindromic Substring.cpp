class Solution {
public:
    int almostPalindromic(string s) {
		int result = 0;
		int const M = s.size();
		if (M == 2)
			return 2;
		string t(s);
		t.pop_back();
		string p = "^";
		p.reserve(M * 2 + 5);
		for (char c : t)
			p += '#', p += c;
		p += "#$";
		int N = p.size();
		{
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
				if (result < LPS[i])
					result = LPS[i];
				if (i + LPS[i] > R)
					R = i + LPS[i], C = i;
			}
		}
		for (int i = M - 2, k = 1; i >= 0; --i, ++k)
		{
			for (int j = i * 2 + 2, idx = i + 1; j < M * 2; j += 2, ++idx)
				p[j] = s[idx];
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
				if (result < LPS[i])
					result = LPS[i];
				if (i + LPS[i] > R)
					R = i + LPS[i], C = i;
			}
		}
		return result + 1;
	}
};
