class Solution {
public:
	bool isPrefixString(string s, vector<string>& words) {
		string t;
		for (string const& w : words)
			if (t.size() < s.size())
				t += w;
			else
				break;
		return t == s;
	}
};