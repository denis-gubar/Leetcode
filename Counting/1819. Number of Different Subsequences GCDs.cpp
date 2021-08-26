class Solution {
public:
	template<typename T> T gcd(T a, T b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	int countDifferentSubsequenceGCDs(vector<int>& nums) {
		int result = 0;
		vector<bool> F(200'001);
		vector<int> divisors(200'001);
		auto add = [&divisors, &F, this](int div, int n)
		{
			if (!F[div])
			{
				if (!divisors[div])
					divisors[div] = n;
				else
				{
					divisors[div] = gcd(divisors[div], n);
					if (divisors[div] == div)
						F[div] = true;
				}
			}
		};
		for (int n : nums)
			if (!F[n])
			{
				F[n] = true;
				for (int x = 1; x * x <= n; ++x)
					if (n % x == 0)
					{
						if (x * x < n)
							add(x, n);
						add(n / x, n);
					}
			}
		for (int i = 0; i < 200'001; ++i)
			result += F[i];
		return result;
	}
};