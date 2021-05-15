class Solution {
public:
	string replaceDigits(string s) {
		int N = s.size();
		for (int i = 0; i < N; i += 2)
			s[i + 1] = s[i] + s[i + 1] - '0';
		return s;
	}
};