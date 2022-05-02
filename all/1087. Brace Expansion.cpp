class Solution {
public:
	void calc(string const& S, string& prefix, int pos, vector<string>& result)
	{
		if (S.size() == pos)
		{
			result.push_back(prefix);
			return;
		}
		if (S[pos] == '{')
		{
			vector<string> options;
			++pos;
			string buffer;
			while (S[pos] != '}')
			{
				if (S[pos] == ',')
				{
					options.push_back(buffer);
					buffer.clear();
				}
				else
					buffer += S[pos];
				++pos;
			}
			options.push_back(buffer);
			++pos;
			int length = prefix.size();
			sort(options.begin(), options.end());
			for (string const& option : options)
			{
				prefix += option;
				calc(S, prefix, pos, result);
				prefix.resize(length);
			}
		}
		else
		{
			prefix += S[pos];
			calc(S, prefix, pos + 1, result);
			prefix.pop_back();
		}
	}
	vector<string> expand(string S) {
		vector<string> result;
		string prefix;
		calc(S, prefix, 0, result);
		return result;
	}
};