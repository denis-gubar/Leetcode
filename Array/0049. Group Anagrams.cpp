class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		int k = 0;
		map<string, int> M;
		for (const string& s : strs)
		{
			string key(s);
			sort(key.begin(), key.end());
			if (M.find(key) == M.end())
			{
				M[key] = k;
				++k;
				result.push_back({ s });
			}
			else
				result[M[key]].push_back(s);
		}
		return result;
	}
};