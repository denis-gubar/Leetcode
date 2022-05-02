class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int a = 0, b = s.size() - 1; a < b; ++a, --b)
			swap(s[a], s[b]);
	}
};