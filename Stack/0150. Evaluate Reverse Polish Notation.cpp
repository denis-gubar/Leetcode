class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<long long> S;
		for (const string& token : tokens)
		{
			if (string{ "+-*/" }.find(token.back()) != string::npos)
			{
				long long b = S.top(); S.pop();
				long long a = S.top(); S.pop();
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
				S.push(atoll(token.c_str()));
		}
		return S.top();
	}
};