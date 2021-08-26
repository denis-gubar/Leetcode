class Solution {
public:
	vector<int> getMaximumXor(vector<int> nums, int maximumBit) {
		vector<int> result;
		int total = (1 << maximumBit) - 1;
		int N = nums.size();
		for (int n : nums)
			total ^= n;
		for (int i = 0; i < N; ++i)
		{
			result.push_back(total);
			total ^= nums.back();
			nums.pop_back();
		}
		return result;
	}
};