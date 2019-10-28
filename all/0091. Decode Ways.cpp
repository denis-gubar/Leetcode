class Solution {
public:
	bool calc(int a, int b)
	{
        int val = ((a - '0') * 10 + b - '0');
		return val > 9 && val <= 26;
	}
	int numDecodings(string s) {
		int N = s.size();
		vector<int> M(N + 1);
		M[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			if (i > 1 && calc(s[i - 2], s[i - 1]))
				M[i] += M[i - 2];
            if (s[i - 1] != '0')
			    M[i] += M[i - 1];
		}
		return M[N];
	}
};