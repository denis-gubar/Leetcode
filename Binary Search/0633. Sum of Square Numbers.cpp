class Solution {
public:
	bool judgeSquareSum(int c) {
		for (long long a = 0; a * a <= c; ++a)
		{
			long long b2 = c - a * a;
			long long b = sqrt(1.0 * b2);
			if (b2 == b * b)
				return true;
		}
		return false;
	}
};