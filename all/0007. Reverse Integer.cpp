class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		long long A = x;
		if (A < 0)
			A = -A;
		while (A)
		{
			if (x < 0)
				result = result * 10 - A % 10;
			else
				result = result * 10 + A % 10;
			A /= 10;
		}
		if (result < numeric_limits<int>::min() || result > numeric_limits<int>::max())
			return 0;
		return result;
	}
};