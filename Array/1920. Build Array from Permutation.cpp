class Solution {
public:
	vector<int> buildArray(vector<int>& nums) {
		int N = nums.size();
		vector<int> result(N);
		for (int i = 0; i < N; ++i)
			result[i] = nums[nums[i]];
		return result;
	}
};