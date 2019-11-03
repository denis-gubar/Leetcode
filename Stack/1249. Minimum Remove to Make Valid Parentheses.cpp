class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string result;
		int balance = 0, count = 0;
		for (char c : s)
			if (c == ')')
			{
				if (balance > 0)
					result += c, --balance;
			}
			else if (c == '(')
				result += c, ++balance, ++count;
			else
				result += c;
		s = result;
		result.clear();
		count -= balance;
		for (char c : s)
			if (c == '(')
			{
				--count;
				if (count >= 0)
					result += c;
			}
			else
				result += c;
		return result;
	}
};