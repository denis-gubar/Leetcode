class Solution {
public:
	int numOfStrings(vector<string>& patterns, string word) {
		int result = 0;
		for (string const& s : patterns)
			if (word.find(s) != string::npos)
				++result;
		return result;
	}
};