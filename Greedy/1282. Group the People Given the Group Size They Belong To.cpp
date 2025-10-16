class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> result;
		map<int, vector<int>> M;
		for (int i = 0; i < groupSizes.size(); ++i)
			M[groupSizes[i]].push_back(i);
		int k = 0;
		for (auto& m : M)
		{
			for (int x : m.second)
			{
				if (k == 0)
					result.push_back({});
				result.back().push_back(x);
				++k;
				if (k == m.first) k = 0;
			}
		}
		return result;
	}
};