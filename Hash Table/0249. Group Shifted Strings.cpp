class Solution {
public:
	string getKey(string const& s)
	{
		string result;
		int delta = 'a' - s[0] + 26;
		for (char c : s)
			result += (c - 'a' + delta) % 26 + 'a';
		return result;
	}
	vector<vector<string>> groupStrings(vector<string>& strings) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> M;
		for (string const& s : strings)
			M[getKey(s)].push_back(s);
		for (auto const& p : M)
			result.push_back(p.second);
		return result;
	}
};