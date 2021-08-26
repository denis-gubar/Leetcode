class Solution {
public:
	void calc(vector<int>& nums, int pos, vector<vector<int>>& result)
	{
		if (pos == nums.size())
		{
			result.push_back(nums);
			return;
		}
		for (int next = pos; next < nums.size(); ++next)
		{
			swap(nums[next], nums[pos]);
			calc(nums, pos + 1, result);
			swap(nums[next], nums[pos]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		calc(nums, 0, result);
		return result;
	}
};