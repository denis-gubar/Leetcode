class Solution {
public:
	int minimumMoves(string s) {
		int result = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == 'X')
			{
				++result;
				i += 2;
			}
		return result;
	}
};