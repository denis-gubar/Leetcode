class Solution {
public:
	int maxNonOverlapping(vector<int>& nums, int target) {
		int N = nums.size();
		vector<int>	F(N + 1);
		vector<int>	A;
		int sum = 0;
		unordered_map<int, int> M;
        M[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			F[i + 1] = F[i];
			sum += nums[i];
			if (M.find(sum - target) != M.end())
				F[i + 1] = max(F[i + 1], F[M[sum - target]] + 1);
			M[sum] = i + 1;
		}
		return F[N];
	}
};