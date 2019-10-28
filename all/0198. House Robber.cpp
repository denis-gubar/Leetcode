class Solution {
public:
	int rob(vector<int>& nums) {
		int N = nums.size();
		vector<vector<int>> M(N + 1, vector<int>(2));
		for (int i = 0; i < N; ++i)
		{
			M[i + 1][0] = max(M[i][0], M[i][1]);
			M[i + 1][1] = M[i][0] + nums[i];
		}
		return max(M[N][0], M[N][1]);
	}
};