class Solution {
public:
	bool isValid(string s) {
		stack<char> S;
		for(char c: s)
			switch (c)
			{
				case '[':
				case '(':
				case '{':
					S.push(c);
					break;
				case ']':
					if (S.empty() || S.top() != '[')
						return false;
					S.pop();
					break;
				case ')':
					if (S.empty() || S.top() != '(')
						return false;
					S.pop();
					break;
				case '}':
					if (S.empty() || S.top() != '{')
						return false;
					S.pop();
					break;
				default:
				break;
			}
		return S.empty();
	}
};