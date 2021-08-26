class Solution {
public:
	bool validPalindrome(string s) {
		int errorCount = 0;
		for (int a = 0, b = s.size() - 1; a < b; ++a, --b)
			if (s[a] != s[b])
				++errorCount, --a;
		if (errorCount < 2)
			return true;
        errorCount = 0;
		for (int a = 0, b = s.size() - 1; a < b; ++a, --b)
			if (s[a] != s[b])
				++errorCount, ++b;
		return errorCount < 2;
	}
};