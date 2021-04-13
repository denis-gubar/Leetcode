class Solution {
public:
	int countSubstrings(string s) {
		int result = 0;
		string t;
		for (char c : s)
		{
			t += '#';
			t += c;
		}
		t += '#';
		for (int i = 1; i < t.size() - 1; ++i)
		{
			int x = 0;
			while (i >= x && i + x < t.size() && t[i - x] == t[i + x])
				++x;
			result += x / 2;
        }
		return result;
	}
};