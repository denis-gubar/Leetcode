class Solution {
public:
	char findTheDifference(string s, string t) {
		int A = 0;
		for (char c : s)
			A ^= 1 << (c - 'a');
		for (char c : t)
			A ^= 1 << (c - 'a');
		for (char i = 'a'; i <= 'z'; ++i)
			if (A & (1 << (i - 'a')))
				return i;
    return 0;
	}
};