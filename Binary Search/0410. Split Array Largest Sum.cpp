class Solution {
public:
	int calc(vector<int> const& nums, int m, int N)
	{
		if (F[m][N] < 0)
		{
			int result = numeric_limits<int>::max();
			if (m == 1)
				result = accumulate(nums.begin(), nums.begin() + N, 0);
			else
			{
				int sum = 0;
				for (int k = 1; N - k >= m - 1; ++k)
				{
					sum += nums[N - k];
					result = min(result, max(calc(nums, m - 1, N - k), sum));
				}
			}
			F[m][N] = result;
		}
		return F[m][N];
	}
	int splitArray(vector<int>& nums, int m) {
		F = vector<vector<int>>(m + 1, vector<int>(nums.size() + 1, -1));
		return calc(nums, m, nums.size());
	}
	vector<vector<int>> F;
};