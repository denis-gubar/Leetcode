class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int>	result;
		partial_sum(nums.begin(), nums.end(), back_inserter(result));
		return result;
	}
};