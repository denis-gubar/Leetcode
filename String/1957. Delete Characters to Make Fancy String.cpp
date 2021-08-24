class Solution {
public:
	string makeFancyString(string s) {
		string result;
		char prev = '$';
		int count = 0;
		for(char c : s)
			if (c != prev)
			{
				result += c;
				count = 1;
				prev = c;
			}
			else
			{
				++count;
				if (count < 3)
					result += c;
			}
		return result;
	}
};