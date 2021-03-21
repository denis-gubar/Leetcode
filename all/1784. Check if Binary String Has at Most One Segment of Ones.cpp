class Solution {
public:
	bool checkOnesSegment(string s) {
		s = "0" + s + "0";
		int count = 0;
		for (int i = 1; i + 1 < s.size(); ++i)
			if (s[i] == '1' && s[i - 1] == '0')
				++count;
		return count < 2;
	}
};