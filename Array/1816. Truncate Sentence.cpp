class Solution {
public:
	string truncateSentence(string s, int k) {
		string result;
		int wordCount = 0;
		for (char c : s)
		{
			if (c == ' ')
			{
				++wordCount;
				if (wordCount == k)
					break;
			}
			result += c;
		}
		return result;
	}
};