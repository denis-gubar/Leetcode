class Solution {
public:
	vector<string> getFolderNames(vector<string>& names) {
		vector<string> result;
		unordered_map<string, int> M;
		for (string const& name : names)
			if (M.find(name) == M.end())
			{
				result.push_back(name);
				++M[name];
			}
			else
			{
				string t;
				do
				{
					t = name + "(" + to_string(M[name]++) + ")";
				} while (M.find(t) != M.end());
				++M[t];
				result.push_back(t);
			}
		return result;
	}
};