class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int result = nums[0], count = 0;
		for (int n : nums)
		{
			if (n != result && --count == 0)
				result = n;
			count += n == result;
		}
		return result;
	}
};