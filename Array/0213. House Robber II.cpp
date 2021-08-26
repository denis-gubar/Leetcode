class Solution {
public:
    int calc(vector<int> const& nums) {
		int N = nums.size();
		vector<vector<int>> M(N + 1, vector<int>(2));
		for (int i = 0; i < N; ++i)
		{
			M[i + 1][0] = max(M[i][0], M[i][1]);
			M[i + 1][1] = M[i][0] + nums[i];
		}
		return max(M[N][0], M[N][1]);
	}
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return max(calc(vector<int>(nums.begin() + 1, nums.end())), calc(vector<int>(nums.begin(), nums.begin() + (nums.size() - 1))));
    }
};