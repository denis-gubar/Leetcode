class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;        
		int a = 0, b = 0, product = 1, N = nums.size();
		while (k > 1 && b < N)
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