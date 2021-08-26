class Solution {
public:
	int singleNumber(vector<int>& nums) {
		long long result = 0, N = nums.size(), p = 1;
		while (true)
		{
			if (N == 1)
				return result + nums[0] * p;
			long long zeroCount = 0, k = 0;
			for (int i = 0; i < N; ++i)
			{
				k += nums[i] % 3;
				zeroCount += nums[i] == 0;
			}
			if (zeroCount == 1)
				return result;
			k = (k % 3 + 3) % 3;
			result += k * p;
			p *= 3;
			N = partition(nums.begin(), nums.begin() + N, [k](int x)
				{
					return (x % 3 + 3) % 3 == k;
				}
			) - nums.begin();
			for (int i = 0; i < nums.size(); ++i)
				nums[i] = (nums[i] - k) / 3;
		}
	}
};