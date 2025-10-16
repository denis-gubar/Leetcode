class Solution {
public:
	int minOperations(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		vector<int> max_bits(N), total_bits(N);
		for (int i = 0; i < N; ++i)
		{
			int x = nums[i];
			while (x)
			{
				++total_bits[i];
				max_bits[i] += x % 2;
				x /= 2;
			}
		}
		result = *max_element(total_bits.begin(), total_bits.end()) - 1;
		result += accumulate(max_bits.begin(), max_bits.end(), 0);
		return result;
	}
};