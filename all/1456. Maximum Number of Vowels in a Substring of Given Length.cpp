class Solution {
public:
	bool isvowel(char c)
	{
		return "aeiou"s.find(c) != string::npos;
	}
	int maxVowels(string s, int k) {
		int result = 0, current = 0;
		for (int i = 0; i < k; ++i)
			current += isvowel(s[i]);
		result = current;
		for (int i = k; i < s.size(); ++i)
		{
			current += isvowel(s[i]);
			current -= isvowel(s[i - k]);
			result = max(result, current);
		}
		return result;
	}
};