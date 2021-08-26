class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
        if (accumulate(nums.begin(), nums.end(), 0LL) <= threshold) return 1;
		int a = 1, b = 2'000'000;        
		while (a + 1 < b)
		{
			int m = (b + a) / 2;
			long long sum = 0;
			for (int n : nums)
				sum += (n + m - 1) / m;
			if (sum > threshold)
				a = m;
			else
				b = m;
		}
		return b;
	}
};