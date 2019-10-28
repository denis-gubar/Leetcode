class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		double current = accumulate(nums.begin(), nums.begin() + k, 0.0);
		double result = current;
		for (int i = 0; i + k < nums.size(); ++i)
		{
			current -= nums[i];
			current += nums[i + k];
			result = max(result, current);
		}
		return result / k;
	}
};