class Solution {
public:
	string decodeString(string s) {
		stack<string> S;
		stack<int> A;
		int x = 0;
		string current;
		for (char c : s)
		{
			if (isdigit(c))
				x = x * 10 + c - '0';
			else if (c == '[')
			{
				A.push(x);
				S.push(current);
				x = 0;
				current.clear();
			}
			else if (c == ']')
			{
				string next;
				for (int i = 0; i < A.top(); ++i)
					next += current;
				A.pop();
				current = S.top() + next;
				S.pop();
			}
			else
				current += c;
		}
        return current;
	}
};