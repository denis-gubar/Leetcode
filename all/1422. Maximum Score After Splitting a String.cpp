class Solution {
public:
	int maxScore(string s) {
		int result = 0;
		for (int length = 1; length < s.size(); ++length)
		{
			int current = 0;
			for (int i = 0; i < length; ++i)
				current += s[i] == '0';
			for (int i = length; i < s.size(); ++i)
				current += s[i] == '1';
			result = max(result, current);
		}
		return result;
	}
};