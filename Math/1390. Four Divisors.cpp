class Solution {
public:
	int check(int n)
	{
		int divs = 2;
        int sum = 1 + n;
		for(int x = 2; x * x <= n; ++x)
			if (n % x == 0)
			{
				if (x * x == n)
					--divs, sum -= x;
				divs += 2;
                sum += x + n / x;
			}
		return (divs == 4) * sum;
	}
	int sumFourDivisors(vector<int>& nums) {
		int result = 0;
		for (int n : nums)
			result += check(n);
		return result;
	}
};