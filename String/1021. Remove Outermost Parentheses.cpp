class Solution {
public:
	string removeOuterParentheses(string S) {
		string result;
		int balance = 0, start = 0;
		for (int i = 0; i < S.size(); ++i)
		{
			auto c = S[i];
			if (c == '(')
			{
				++balance;
				if (balance == 1)
					start = i;
			}
			else
				--balance;
			if (balance == 0)
			{
				int length = i - start - 1;
				result += S.substr(start + 1, length);
			}
		}
		return result;
	}
};