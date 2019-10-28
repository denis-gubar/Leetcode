class Solution {
public:
	string reverseParentheses(string s) {
		stack<string> S;
		S.push({});
		for (char c : s)
			if (c == '(')
				S.push({});
			else if (c == ')')
			{
				string substring = S.top(); S.pop();
				reverse(substring.begin(), substring.end());
				S.top() += substring;
			}
			else
				S.top() += c;
		return S.top();
	}
};