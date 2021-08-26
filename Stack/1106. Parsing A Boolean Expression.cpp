class Solution {
public:
	vector<string> split(const string& s, char delimeter = ',')
	{
		vector<string> result;
		istringstream ss(s);
		for (string token; !ss.eof(); )
		{
			getline(ss, token, delimeter);
			result.push_back(token);
		}
		return result;
	}
	bool calc(string const& expression, int start, int length)
	{
		if (length == 1)
		{
			if (expression[start] == 'f')
				return false;
			if (expression[start] == 't')
				return true;
		}
		if (expression[start] == '!')
			return !calc(expression, start + 2, length - 3);
		if (expression[start] == '|' || expression[start] == '&')
		{
			bool result = expression[start] == '&';
			int balance = 0;
			int s = start + 2;
			for (int pos = start + 2; pos + 1 <= start + length; ++pos)
			{
				if ((pos + 1 == start + length || expression[pos] == ',') && !balance)
				{
					if (expression[start] == '|')
						result |= calc(expression, s, pos - s);
					else
						result &= calc(expression, s, pos - s);
					s = pos + 1;
				}
				else if (expression[pos] == '(')
					++balance;
				else if (expression[pos] == ')')
					--balance;
			}
            return result;
		}
		return false;
	}
	bool parseBoolExpr(string expression) {		
		return calc(expression, 0, expression.size());
	}
};