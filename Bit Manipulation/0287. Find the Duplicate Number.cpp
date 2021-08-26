class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int N = nums.size() - 1;
		int a = 1, b = N;
		while (a < b)
		{
			int m = (a + b) / 2;
			int left_length = m - a + 1;
			int count = 0;
			for (int n : nums)
				count += n >= a && n <= m;
			if (left_length < count)
				b = m;
			else
				a = m + 1;
		}
		return a;
	}
};