class Solution {
public:
	int maxPower(string s) {
		int result = 1, current = 1;
		int N = s.size();
		s += '$';
		for (int i = 0; i < N; ++i)
			if (s[i] == s[i + 1])
			{
				++current;
				result = max(result, current);
			}
			else
				current = 1;
		return result;
	}
};