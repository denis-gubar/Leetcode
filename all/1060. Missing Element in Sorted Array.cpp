class Solution {
public:
	int missingElement(vector<int>& nums, int k) {
		int result = nums[0];
		int N = nums.size();
		int missingCount = nums[N - 1] - nums[0] - N + 1;
		int a = 0, b = N - 1;
		if (missingCount < k)
			a = N - 1;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			missingCount = nums[m] - nums[0] - m;
			if (missingCount == k)
				return nums[m] - 1;
			if (missingCount < k)
				a = m;
			else
				b = m;
		}
		return nums[a] + k - (nums[a] - nums[0] - a);
	}
};