static short F[501][501];
class Solution {
public:
	int calc(string const& s, int start, int length)
	{
		if (length < 2) return 0;
		if (F[start][length] < 0)
		{
			if (s[start] == s[start + length - 1])
				return F[start][length] = calc(s, start + 1, length - 2);
			F[start][length] = min(calc(s, start + 1, length - 1),
				calc(s, start, length - 1)) + 1;
		}
		return F[start][length];
	}
	int minInsertions(string s) {
		int N = s.size();
		memset(F, -1, sizeof(F));
		return calc(s, 0, N);
	}	
};