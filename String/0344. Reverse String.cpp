class Solution {
public:
	string reverseString(string s) {
		string result;
		for (int i = s.size() - 1; i >= 0; --i)
			result += s[i];
		return result;
	}
};