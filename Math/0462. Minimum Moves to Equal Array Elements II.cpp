class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int N = nums.size();
		auto calc = [&nums](int x)
		{
			long long result = 0;
			for (long long z : nums)
				result += abs(x - z);
            return result;
		};
        nth_element(nums.begin(), nums.begin() + N / 2, nums.end());
		return calc(nums[N / 2]);
	}
};