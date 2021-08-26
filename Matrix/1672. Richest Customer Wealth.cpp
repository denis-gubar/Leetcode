class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int result = 0;
		for (vector<int> const& a : accounts)
			result = max(result, accumulate(a.begin(), a.end(), 0));
		return result;
	}
};