class Solution {
public:
	vector<int> targetIndices(vector<int>& nums, int target) {
		vector<int> result;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			if (nums[i] == target)
				result.push_back(i);
		return result;

	}
};