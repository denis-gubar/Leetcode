class Solution {
public:
	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		int G = groups.size(), N = nums.size();
		int pos = 0;
		for (int i = 0; i < G; ++i)
		{
			auto it = search(nums.begin() + pos, nums.end(), groups[i].begin(), groups[i].end());
			if (it == nums.end())
				return false;
			pos = it - nums.begin();
			pos += groups[i].size();
		}
		return true;
	}
};