class Solution {
public:
	void calc(const vector<int>& candidates, vector<int>& prefix, int lastI, int target, vector<vector<int>>& result)
	{
		if (target == 0)
		{
			result.push_back(prefix);
			return;
		}
		for (int i = lastI; i < candidates.size(); ++i)
		{
			int x = 0;
			for (int delta = candidates[i]; delta <= target; delta += candidates[i], ++x)
			{
				prefix.push_back(candidates[i]);
				calc(candidates, prefix, i + 1, target - delta, result);
			}
			for (int k = 0; k < x; ++k)
				prefix.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> prefix;
		calc(candidates, prefix, 0, target, result);
		return result;
	}
};