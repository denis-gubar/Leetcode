class Solution {
public:
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
		vector<int> result(k);
		unordered_map<int, unordered_set<int>> M;
		for (vector<int> const& log : logs)
		{
			int const& ID = log[0];
			int const& time = log[1];
			M[ID].insert(time);
		}
		for (auto& [key, value] : M)
			if (value.size() <= k)
				++result[value.size() - 1];
		return result;
	}
};