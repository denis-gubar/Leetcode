class Solution {
public:
	vector<int> getConcatenation(vector<int>& nums) {
		vector<int> result(nums);
		copy(nums.begin(), nums.end(), back_inserter(result));
		return result;
	}
};