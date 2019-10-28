class Solution {
public:
	void calc(const vector<int>& nums, int lastI, vector<int>& prefix, vector<vector<int>>& result)
	{
		if (lastI == nums.size())
		{
			result.push_back(prefix);
			return;
		}
		for (int i = lastI; i < nums.size(); ++i)
		{
			prefix.push_back(nums[i]);
			calc(nums, i + 1, prefix, result);
			prefix.pop_back();
		}
		calc(nums, nums.size(), prefix, result);
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> prefix;
		calc(nums, 0, prefix, result);
		return result;
	}
};