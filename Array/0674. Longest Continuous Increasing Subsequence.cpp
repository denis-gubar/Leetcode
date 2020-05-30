class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		int result = 1;
		int current = 1;
		int prev = nums[0];
		for (int n : nums)
		{
			if (n <= prev)
			{
				result = max(result, current);
				current = 1;
			}
			else
			{
				++current;
				result = max(result, current);
			}
			prev = n;
		}
		return result;
	}
};