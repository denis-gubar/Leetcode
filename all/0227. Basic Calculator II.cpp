class Solution {
public:
	int calculate(string s) {
		long long result = 0;
		s += '=';
		vector<long long> values, operations;
		long long x = 0;
		for (int c : s)
			if (c != ' ')
			{
				if (isdigit(c))
					x = x * 10 + c - '0';
				else
				{
					values.push_back(x);
					x = 0;
					operations.push_back(c);
				}
			}
		reverse(values.begin(), values.end());
		reverse(operations.begin(), operations.end());
        result = values.back();
		while (values.size() > 1)
		{
			if (operations.size() > 1 && (operations.back() == '-' || operations.back() == '+') &&
				(operations[operations.size() - 2] == '*' || operations[operations.size() - 2] == '/'))
			{
				long long curValue = values.back();
				int curOperation = operations.back();
				values.pop_back();
				operations.pop_back();
				if (operations.back() == '*')
					result = values.back() * values[values.size() - 2];
				else
					result = values.back() / values[values.size() - 2];
				operations.pop_back();
				values.pop_back();
				values.back() = result;
				values.push_back(curValue);
				operations.push_back(curOperation);
			}
			else
			{
				if (operations.back() == '*')
					result = values.back() * values[values.size() - 2];
				else if (operations.back() == '/')
					result = values.back() / values[values.size() - 2];
				else if (operations.back() == '+')
					result = values.back() + values[values.size() - 2];
				else if (operations.back() == '-')
					result = values.back() - values[values.size() - 2];
				else
				{
					result = values.back();
					break;
				}
				values.pop_back();
				operations.pop_back();
				values.back() = result;
			}
		}
		return result;
	}
};