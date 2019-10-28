class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		vector<string> result;
		sort(folder.begin(), folder.end());
		int k = 0;
		result.push_back(folder[0]);
		for (int i = 1; i < folder.size(); ++i)
			if (folder[i].size() <= folder[k].size() || 
                !equal(folder[i].begin(), folder[i].begin() + folder[k].size(), folder[k].begin()) || folder[i][folder[k].size()] != '/')
				{
					k = i;
					result.push_back(folder[i]);
				}
		return result;
	}
};