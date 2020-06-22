class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int result = *max_element(nums.begin(), nums.end());
		nums.push_back(0);
		int a = 0, b = 0, product = 1, negativeCount = 0;
		while (b < nums.size())
		{
			if (nums[b] == 0)
			{
				while (product < 0)
					product /= nums[a], ++a;
				if (a < b)
					result = max(result, product);
				a = b + 1, product = 1;
			}
			else
			{
				product *= nums[b];
				result = max(result, product);
			}
			++b;
		}
		return result;
	}
};