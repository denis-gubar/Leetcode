class Solution {
public:
	vector<string> split(const string& s, char delimeter = ' ')
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
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> M;
		for (string const& p : paths)
		{
			vector<string> S(split(p));
			auto update = [&M](string const& p, string const& prefix)
			{
				int pos = p.find('(');
				string_view value(p.c_str(), pos);
				string_view key(p.c_str() + pos, p.size() - pos);
				M[string(key)].push_back(prefix + string(value));
			};
			if (S.size() == 1)
				update(p, {});
			else
			{
				for (int i = 1; i < S.size(); ++i)
					update(S[i], S[0] + '/');
			}
		}
		for (auto& [key, value] : M)
			if (value.size() > 1)
				result.push_back(value);
		return result;
	}
};