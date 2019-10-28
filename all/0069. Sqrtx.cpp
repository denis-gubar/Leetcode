class Solution {
public:
	int mySqrt( int x ) {
		if (x <= 1)
		{
			return x;
		}
		int result = 0;
		int a = 0, b = x;
		while (a + 1 < b)
		{
			long long m = (a + b) / 2;
			if (m * m == x)
				return m;
			if (m * m < x)
			{
				a = m;
			}
			else
			{
				b = m;
			}
		}
		return a;
	}
};