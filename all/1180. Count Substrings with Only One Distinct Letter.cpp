class Solution {
public:
	int countLetters(string S) {
		int result = 0;
		S = '^' + S + '$';
		int x = 0;
		for (int i = 1; i < S.size(); ++i)
			if (S[i] != S[i - 1])
				result += x * (x + 1) / 2, x = 1;
			else
				++x;
		return result;
	}
};