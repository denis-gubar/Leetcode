class Solution {
public:
	int numberOfSubarrays(vector<int>& nums, int k) {
		int result = 0;
		int odd = 0, a = 0, N = nums.size(), b = 0, startA = 0, startB = 0, endA = 0, endB = 0;
		while (b < N)
		{
			odd += nums[b] % 2;
			if (odd == k)
			{
				startA = a, startB = b, endA = a, endB = b;
				while (b + 1 < N && nums[b + 1] % 2 == 0)
					++b, ++endB;
				while (nums[a] % 2 == 0)
					++a, ++endA;
				result += (endA - startA + 1) * (endB - startB + 1);
				--odd; ++a;
			}
			++b;
		}
        return result;
	}
};