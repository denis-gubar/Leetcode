class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 2) return 0;
		int result = 0;        
		int a = 0, b = 0, product = 1;
		while (b < nums.size())
		{
			product *= nums[b];
			while (product >= k)
				product /= nums[a], ++a;
            result += b - a + 1;
            ++b;
		}
		return result;
	}
};