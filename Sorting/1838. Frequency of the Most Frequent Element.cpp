class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		int result = 1;
		int N = nums.size();
		sort(nums.begin(), nums.end());
		int a = 0, b = 1;
		long long sum = 0;
		while (b < N)
		{
			sum += 1LL * (nums[b] - nums[b - 1]) * (b - a);
			while (sum > k)
			{
				sum -= nums[b] - nums[a];
				++a;
			}
			result = max(result, b - a + 1);
			++b;
		}
		return result;
	}
};