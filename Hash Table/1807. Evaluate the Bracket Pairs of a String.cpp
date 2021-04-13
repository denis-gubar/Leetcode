class Solution {
public:
	string evaluate(string s, vector<vector<string>>& knowledge) {
		unordered_map<string, string> M;
		for (vector<string> const& k : knowledge)
		{
			string const& key = k[0];
			string const& value = k[1];
			M[key] = value;
		}
		string result;
		string key;
		bool isKey = false;
		for (char c : s)
		{
			if (c == '(')
				isKey = true;
			else if (c == ')')
			{
				auto it = M.find(key);
				if (it == M.end())
					result += '?';
				else
					result += it->second;
				key.clear();
                isKey = false;
			}
			else
			{
				if (isKey)
					key += c;
				else
					result += c;
			}
		}
		return result;
	}
};