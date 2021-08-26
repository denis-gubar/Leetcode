class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		int N = nums.size();
		vector<int> result;
		for (int i = 0; i < N; ++i)
			result.insert(result.begin() + index[i], nums[i]);
		return result;
	}
};