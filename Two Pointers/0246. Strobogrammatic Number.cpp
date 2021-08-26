class Solution {
public:
	bool isStrobogrammatic(string num) {
		string from{ "01869" };
		string to{ "01896" };
		string s(num);
		reverse(s.begin(), s.end());
		for (int i = 0; i < num.size(); ++i)
			if (int pos = from.find(num[i]); pos == string::npos || s[i] != to[pos])
				return false;
		return true;
	}
};