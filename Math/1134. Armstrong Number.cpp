class Solution {
public:
	int power(int n, int k)
	{
		int result = 1;
		for (int i = 0; i < k; ++i)
			result *= n;
		return result;
	}
	bool isArmstrong(int N) {
		int k = 0;
		int n = N;
		while (n)
		{
			++k;
			n /= 10;
		}
		n = N;
		int sum = 0;
		while (n)
		{
			sum += power(n % 10, k);
			n /= 10;
		}
		return sum == N;
	}
};