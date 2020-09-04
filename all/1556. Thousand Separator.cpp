class Solution {
public:
	string thousandSeparator(int n) {
		string result;
		string s = to_string(n);
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)
		{
			if (i && i % 3 == 0)
				result += '.';
			result += s[i];
		}
		reverse(result.begin(), result.end());
		return result;
	}
};