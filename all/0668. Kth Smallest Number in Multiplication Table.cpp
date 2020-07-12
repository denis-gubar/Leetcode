class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int a = 0, b = m * n;
		while (a + 1 < b)
		{
			int z = (a + b) / 2;
			int count = 0;
			for (int width = 1; width <= m; ++width)
				count += min(z / width, n);
			if (count >= k)
				b = z;
			else
				a = z;
		}
		return b;
	}
};