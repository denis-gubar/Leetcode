class Solution {
public:
	int maxDepth(string s) {
		int result = 0;
		int balance = 0;
		for (char c : s)
			if (c == '(')
			{
				++balance;
				result = max(result, balance);
			}
			else if (c == ')')
				--balance;
		return result;
	}
};