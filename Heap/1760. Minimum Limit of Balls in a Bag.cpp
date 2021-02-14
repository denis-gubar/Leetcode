class Solution {
public:
	int minimumSize(vector<int>& nums, int maxOperations) {
		int N = nums.size();
		int a = 0, b = *max_element(nums.begin(), nums.end());
		auto calc = [&nums, maxOperations](int x)
		{
			int result = 0;
			for (int n : nums)
				result += (n + x - 1) / x - 1;
			return result <= maxOperations;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};