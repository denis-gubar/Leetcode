class Solution {
public:
	bool checkRecord(string s) {
		if (count(s.begin(), s.end(), 'A') > 1)
			return false;
		if (s.find("LLL") != string::npos)
			return false;
		return true;
	}
};