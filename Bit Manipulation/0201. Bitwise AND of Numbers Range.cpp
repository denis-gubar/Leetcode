class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int result = m & n;
		int k = 0;
		while (n && m <= n)
		{
			result = result & n;
			int mask = ~(1 << k);
			n = (n >> k << k) & mask;
			++k;
		}
		return result;
	}
};