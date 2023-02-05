class Solution {
public:
	bool check(string const& s, int prefixSize)
	{
		for (int i = prefixSize; i < s.size(); ++i)
			if (s[i] != s[i % prefixSize])
				return false;
		return true;
	}
	string gcdOfStrings(string str1, string str2) {
		for (int i = str1.size(); i > 0; --i)
			if (str1.size() % i == 0 && str2.size() % i == 0 && str1.substr(0, i) == str2.substr(0, i) &&
				check(str1, i) && check(str2, i))
				return str1.substr(0, i);
		return {};
	}
};