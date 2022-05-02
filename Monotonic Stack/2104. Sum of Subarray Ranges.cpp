class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long result = 0;
		int N = nums.size();
		for (int start = 0; start < N; ++start)
		{
			int a = nums[start], b = nums[start];
			for (int finish = start; finish < N; ++finish)
			{
				a = min(a, nums[finish]);
				b = max(b, nums[finish]);
				result += b - a;
			}
		}
		return result;
	}
};