class Solution {
public:
	int maxValue(long long n, long long index, long long maxSum) {
		maxSum -= n;
		long long a = 0, b = 1'000'000'001;
		while (a + 1 < b)
		{
			long long m = (a + b) / 2;
			long long sum = m;
			long long left = min(m - 1, index);
			long long right = min(m - 1, n - index - 1);
			sum += (left + 1) * left / 2 + left * (m - left - 1);
			sum += (right + 1) * right / 2 + right * (m - right - 1);
			if (sum <= maxSum)
				a = m;
			else
				b = m;
		}
		return b;
	}
};