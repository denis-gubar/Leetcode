class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 0;
		while (n)
		{
			n &= n - 1;
			++result;
		}
		return result;
	}
};