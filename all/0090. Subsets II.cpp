class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int N = nums.size();
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			vector<int> A;
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					A.push_back(nums[k]);
			result.push_back(A);
		}
		sort(result.begin(), result.end());
		result.resize(unique(result.begin(), result.end()) - result.begin());
		return result;
	}
};