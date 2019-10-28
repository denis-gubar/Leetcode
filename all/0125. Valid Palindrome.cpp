class Solution {
public:
	bool isPalindrome(const string& s) {
		int N = s.size();
		int a = 0, b = N - 1;
		while (a < b)
		{
			if (!isalnum(s[a]))
			{
				++a; continue;
			}
			if (!isalnum(s[b]))
			{
				--b; continue;
			}
			if (tolower(s[a]) != tolower(s[b]))
				return false;
			++a, --b;
		}
		return true;
	}
};