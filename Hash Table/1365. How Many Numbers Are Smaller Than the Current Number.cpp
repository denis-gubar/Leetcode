class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> result(nums.size());
		for (int i = 0; i < nums.size(); ++i)
			for (int j : nums)
				result[i] += nums[i] > j;
		return result;
	}
};