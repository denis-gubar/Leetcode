class Solution {
public:
	int check(int n)
	{
		int divs = 0;
        int sum = 0;
		for(int x = 1; x * x <= n; ++x)
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