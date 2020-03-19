class Solution {
public:
	int maximum(vector<int> const& nums, int a, int b)
	{
		if (!M[a][b])
			M[a][b] = *max_element(nums.begin() + a, nums.begin() + b + 1);
		return M[a][b];
	}
	int calc(vector<int> const& nums, int m, int N)
	{
		if (F[m][N] < 0)
		{
			int result = numeric_limits<int>::max();
			if (m == 1)
				result = maximum(nums, 0, N - 1);
			else
			{
				int sum = nums[N - 1];
				for (int k = 1; N - k >= m - 1; ++k)
				{
					sum = max(sum, nums[N - k]);
					result = min(result, calc(nums, m - 1, N - k) + sum);
				}
			}
			F[m][N] = result;
		}
		return F[m][N];
	}
	vector<vector<int>> F;
	vector<vector<int>> M;
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		F = vector<vector<int>>(d + 1, vector<int>(jobDifficulty.size() + 1, -1));
		M = vector<vector<int>>(jobDifficulty.size(), vector<int>(jobDifficulty.size(), 0));
        int result = calc(jobDifficulty, d, jobDifficulty.size());
        if (result == numeric_limits<int>::max())
            result = -1;
		return result;
	}
};