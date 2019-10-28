class Solution {
private:
	vector<int> memo;
public:
	Solution()  {
		memo = vector<int>(32);
	}
	int calc(int num)
	{
		if (num == 0)
			return 0;
		if (memo[num] != 0)
			return memo[num];
		if (num == 1)
			return memo[num] = 2;
		if (num == 2)
			return memo[num] = 3;
		return calc(num - 1) + calc(num - 2);
	}
	int findIntegers(int num) {
		if (num < 3)
			return num + 1;
        if (num == 3)
            return 3;
		int result = 0;
		int k = 0, n = num;
		vector<int> bits;
		while (n)
		{
			bits.push_back(n % 2);
			n = n >> 1;
			++k;
		}
		reverse(bits.begin(), bits.end());
		result = result + calc(k - 1);
		if (bits[1] == 1)
			return result + calc(k - 2);
		return result + findIntegers(num - (1 << (k - 1)));
	}
};
