class Solution {
public:
	int const INF = 1 << 30;
	int N, M;
	int calc(int begin, int end, int i)
	{
		if (i == M)
			return 0;
		if (F[begin][i] == -INF)
		{
			int A = calc(begin + 1, end, i + 1) + multipliers[i] * nums[begin];
			int B = calc(begin, end - 1, i + 1) + multipliers[i] * nums[end];
			F[begin][i] = max(A, B);
		}
		return F[begin][i];
	}
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		this->nums = nums;
		this->multipliers = multipliers;
		N = nums.size(), M = multipliers.size();
		F = vector<vector<int>>(M, vector<int>(M, -INF));
		return calc(0, N - 1, 0);
	}
	vector<vector<int>> F;
	vector<int> nums;
	vector<int> multipliers;
};