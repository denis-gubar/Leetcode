class Solution {
public:
	string modifyString(string s) {
		string result;
		for(char c : s)
			if (c == '?')
			{
				if (result.empty())
					result += 'a';
				else
					result += (result.back() - 'a' + 1) % 26 + 'a';
			}
			else
			{				
				if (!result.empty() && result.back() == c)
					result.back() = (result.back() - 'a' + 24) % 26 + 'a';
				result += c;
			}
		return result;
	}
};