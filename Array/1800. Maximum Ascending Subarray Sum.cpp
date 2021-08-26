class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int result = 0;
		int prev = 0, sum = 0;
		nums.push_back(0);
		for(int n : nums)
			if (n > prev)
			{
				prev = n;
				sum += n;
			}
			else
			{
				result = max(result, sum);
				prev = n;
				sum = n;
			}
		nums.pop_back();
        return result;
	}
};