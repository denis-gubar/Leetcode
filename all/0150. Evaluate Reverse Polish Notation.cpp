class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> S;
		for (const string& token : tokens)
		{
			if (string{ "+-*/" }.find(token.back()) != string::npos)
			{
				int b = S.top(); S.pop();
				int a = S.top(); S.pop();
				if (token == "+")
					S.push(a + b);
				else if (token == "-")
					S.push(a - b);
				else if (token == "*")
					S.push(a * b);
				else
					S.push(a / b);
			}
			else
				S.push(atoi(token.c_str()));
		}
		return S.top();
	}
};