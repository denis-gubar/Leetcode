class Solution {
public:
	int missingElement(vector<int>& nums, int k) {
		int N = nums.size();
		int a = 0, b = N;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (nums[m] - nums[0] - m < k)
				a = m;
			else
				b = m;
		}
		return nums[0] + k + a;
	}
};