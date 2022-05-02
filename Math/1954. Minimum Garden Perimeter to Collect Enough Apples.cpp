class Solution {
public:
	long long calc(long long x)
	{
		long long result = 0;
		for (long long k = 1; k <= x / 2; ++k)
			result += k * k;
		for (long long k = x / 2 + 1, a = x / 2; k <= x; ++k, --a)
			result += k * a;
		return result * 4;
	}
	long long minimumPerimeter(long long neededApples) {
		long long a = 0, b = 1'000'000;
		while (a + 1 < b)
		{
			long long m = (a + b) / 4 * 2;
            if (m == a || m == b)
                break;
			if (calc(m) >= neededApples)
				b = m;
			else
				a = m;
		}
		return 4 * b;
	}
};