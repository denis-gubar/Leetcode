class Solution {
public:
	int countMaxOrSubsets(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		int best = 0;
		for (int mask = 1; mask < (1 << N); ++mask)
		{
			int orResult = 0;
			for(int k = 0; k < N; ++k)
				if (mask & (1 << k))
					orResult |= nums[k];
			if (orResult > best)
				best = orResult, result = 0;
			if (orResult == best)
				++result;
		}
		return result;
	}
};