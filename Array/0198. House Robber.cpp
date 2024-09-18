class Solution {
public:
	int rob(vector<int>& nums) {
		int N = nums.size();
		vector<vector<int>> M(2, vector<int>(N + 1));
		for (int i = 0; i < N; ++i)
		{
			M[0][i + 1] = max(M[0][i], M[1][i]);
			M[1][i + 1] = M[0][i] + nums[i];
		}
		return max(M[0][N], M[1][N]);
	}
};