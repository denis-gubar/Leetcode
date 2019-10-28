class Solution {
public:
	int minAddToMakeValid(string S) {
		int result = 0;
		int stack = 0;
		for (char c : S)
			if (c == '(')
			{
				++stack;
			}
			else
			{
				if (stack > 0)
					--stack;
				else
					++result;
			}
		result += stack;
		return result;
	}
};