class Solution {
public:
	int calc(vector<int> const& A, int target)
	{
		if (F[target] < 0)
		{
			F[target] = 0;
			for (int a : A)
				if (a <= target)
					F[target] += calc(A, target - a);
				else
					break;
		}
		return F[target];
	}
	int combinationSum4(vector<int>& nums, int target) {
		int result = 0;
		F = vector<int>(target + 1, -1);
		F[0] = 1;
		sort(nums.begin(), nums.end());		
		return calc(nums, target);
	}
	vector<int> F;
};