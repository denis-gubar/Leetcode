class Solution {
public:
	int jump(vector<int>& nums) {
		int result = 0;
		int pos = 0, N = nums.size();
		int jump0 = 0, jump1 = 0;
		while (pos < N - 1)
		{
			if (jump0 == 0)
				++result, jump0 = max(jump1, nums[pos]) - 1, jump1 = 0;
			else
				--jump0, jump1 = max(jump1, nums[pos]) - 1;
			++pos;
		}
		return result;
	}
};