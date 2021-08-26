class Solution {
public:
	Solution()
	{
		maxPowerOfThree = 3;
		while (maxPowerOfThree * 3LL < numeric_limits<int>::max())
			maxPowerOfThree *= 3;
	}
	bool isPowerOfThree(int n) {
		return n > 0 && maxPowerOfThree % n == 0;
	}
	int maxPowerOfThree;
};