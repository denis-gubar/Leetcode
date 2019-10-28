class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.empty())
			return -1;
		int right = accumulate(nums.begin() + 1, nums.end(), 0);
		if (!right)
			return 0;
		int left = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			left += nums[i - 1];
			right -= nums[i];
			if (left == right)
				return i;
		}
		return -1;
	}
};