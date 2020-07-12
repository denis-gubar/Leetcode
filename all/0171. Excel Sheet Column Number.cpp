class Solution {
public:
	int titleToNumber(string s) {
		reverse(s.begin(), s.end());
		long long k = 1;
		int result = 0;
		for (char c : s)
		{
			int x = c - 'A' + 1;
			result += k * x;
			k *= 26;
		}
		return result;
	}
};