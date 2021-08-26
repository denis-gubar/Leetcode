class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int N = nums.size(), M = nums[0].size();
		if (N * M != r * c)
			return nums;
		vector<vector<int>> result(r, vector<int>(c));
		for (int x = 0; x < r * c; ++x)
			result[x / c][x % c] = nums[x / M][x % M];
		return result;
	}
};