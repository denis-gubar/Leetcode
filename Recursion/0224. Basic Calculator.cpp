class Solution {
public:
	int calculate(string s) {
        s += '+';
		stack<pair<int, char>> S;
		S.push({ 0, '+' });
		string buffer;
		auto flush = [&S, &buffer]()
		{
            if (buffer.empty())
                return;
			int right = stoi(buffer); buffer.clear();
			if (S.top().second == '+')
				S.top().first += right;
			else
				S.top().first -= right;
		};
		auto pop = [&S]()
		{
			int val = S.top().first; S.pop();
			if (S.top().second == '+')
				S.top().first += val;
			else
				S.top().first -= val;
		};
		for (char c : s)
		{
			if (c == ' ')
				continue;
			if (c == '(')
			{
				S.push({ 0, '+' });
				continue;
			}
			if (c == ')')
			{
				flush();
				pop();
				continue;
			}
			if (c == '+' || c == '-')
			{
				flush();
                S.top().second = c;
				continue;
			}
			buffer += c;
		}
		return S.top().first;
	}
};