class Solution {
public:
	int minOperations(vector<int>& nums) {
		int N = nums.size();
		int result = N;
    sort(nums.begin(), nums.end());
		nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
		int delta = 0;
		auto it = nums.begin();
		for (int x : nums)
		{
			while (it != nums.end() && *it - x <= N - 1)
			{
				++it;
				++delta;
			}
			result = min(result, N - delta);
			--delta;
		}
		return result;
	}
};