class Solution {
public:
	int sign(int x)
	{
		if (x > 0) return 1;
		if (x < 0) return -1;
		return 0;
	}
	int arraySign(vector<int>& nums) {
		int result = sign(nums[0]);
		for (int i = 1; i < nums.size(); ++i)
			result *= sign(nums[i]);
		return result;
	}
};