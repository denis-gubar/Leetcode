class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		unordered_map<int, vector<int>> M;
		int N = values.size();
		for (int i = 0; i < N; ++i)
			M[labels[i]].push_back(values[i]);
		vector<int>	filtered;
		for (auto& p : M)
			if (p.second.size() <= use_limit)
			{
				copy(p.second.begin(), p.second.end(), back_inserter(filtered));
			}
			else
			{
				nth_element(p.second.begin(), p.second.begin() + (use_limit - 1), p.second.end(), greater<int>());
				copy(p.second.begin(), p.second.begin() + use_limit, back_inserter(filtered));
			}
		sort(filtered.begin(), filtered.end(), greater<int>());
		int result = 0;
		for (int i = 0; i < num_wanted && i < filtered.size(); ++i)
			result += filtered[i];
		return result;
	}
};