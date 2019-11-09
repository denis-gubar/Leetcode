class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.empty()) return 0;
		int N = nums.size();
		vector<int> F{ 1, 1 };
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] == nums[i - 1])
				continue;
			if (nums[i] < nums[i - 1])
				F[1] = max(F[1], F[0] + 1);
			else
				F[0] = max(F[0], F[1] + 1);
		}
		return max(F[0], F[1]);
	}
};