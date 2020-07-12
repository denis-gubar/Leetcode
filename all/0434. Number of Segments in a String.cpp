class Solution {
public:
	int countSegments(string s) {
		int result = 0;
		char prev = ' ';
		for (char c : s)
		{
			if (c == ' ')
			{
				prev = ' ';
			}
			else
			{
				result += prev == ' ';
				prev = c;
			}
		}
		return result;
	}
};