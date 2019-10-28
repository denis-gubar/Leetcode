class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> M;
		for (int i = 0; i < nums.size(); ++i)
			if (M.find(target - nums[i]) == M.end())
				M[nums[i]] = i;
			else
				return { M.find(target - nums[i])->second, i };
		return {};
	}
};