class Solution {
public:
	long long eval(string_view s)
	{
		long long left = 0, k = 1, sign = 1, delta = 0;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '+')
				return delta + sign * left * k + eval(s.substr(i + 1));
			else if (s[i] == '-')
				delta += sign * left * k, sign = -1, k = 1, left = 0;
			else if (s[i] == '*')
				k *= left, left = 0;
			else
				left = left * 10 + (s[i] - '0');
		return delta + sign * left * k;
	}
	void generate(string const& num, int target, string& prefix, int pos, long long current, bool isFirst, vector<string>& result)
	{
		if (pos == num.size())
		{
			if (eval(prefix) == target)
				result.push_back(prefix);
			return;
		}
		if (isFirst || current != 0)
		{
			prefix += num[pos];
			generate(num, target, prefix, pos + 1, current * 10 + num[pos] - '0', false, result);
			prefix.pop_back();
		}
		if (!isFirst)
		{
			prefix += '+';
			generate(num, target, prefix, pos, 0, true, result);
			prefix.back() = '-';
			generate(num, target, prefix, pos, 0, true, result);
			prefix.back() = '*';
			generate(num, target, prefix, pos, 0, true, result);
			prefix.pop_back();
		}
	}
	vector<string> addOperators(string num, int target) {
		vector<string> result;
		string prefix;
		generate(num, target, prefix, 0, 0, true, result);
		sort(result.begin(), result.end());
		return result;
	}
};