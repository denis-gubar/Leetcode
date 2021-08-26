class Solution {
public:
	int countSpecialSubsequences(vector<int>& nums) {
		int const MOD = 1'000'000'007;
		int N = nums.size();
		vector<vector<long long>> F(4, vector<long long>(N + 1));
		F[0][0] = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < 4; ++j)
				F[j][i + 1] = F[j][i];
			int j = nums[i] + 1;
			F[j][i + 1] += F[j][i];
			F[j][i + 1] += F[j - 1][i];
			F[j][i + 1] %= MOD;			
		}
		return F[3][N];
	}
};