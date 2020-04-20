class Solution {
public:
	string reformat(string s) {
		string result;
		string digits;
		string letters;
		for (char c : s)
			if (isdigit(c))
				digits += c;
			else
				letters += c;
		int d = digits.size(), l = letters.size();
		if (abs(d - l) > 1)
			return "";
		if (l > d)
			result += letters.back(), letters.pop_back();
		while (!digits.empty())
		{
			result += digits.back(), digits.pop_back();
			if (!letters.empty())
				result += letters.back(), letters.pop_back();
		}
		return result;
	}
};