class Solution {
public:
	int arrangeCoins(int n) {
		int a = 0, b = max(4, n / 2);
		while (a + 1 < b)
		{
			long long m = a + (b - a) / 2;
			if (m * (m + 1) / 2 <= n)
				a = m;
			else
				b = m;
		}
		return a;
	}
};