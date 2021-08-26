class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int result = 0;
		sort(nums.begin(), nums.end(), greater<int>());
		while (!nums.empty() && nums.back() == 0)
			nums.pop_back();
		reverse(nums.begin(), nums.end());
		int N = nums.size();
		for (int a = 0; a < N; ++a)
			for (int b = a + 1; b < N; ++b)
			{
				auto it = lower_bound(nums.begin(), nums.end(), nums[a] + nums[b]);
				result += it - (nums.begin() + b + 1);
			}
		return result;
	}
};