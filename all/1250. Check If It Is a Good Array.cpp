class Solution {
public:
	template<typename T> T gcd(T a, T b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	bool isGoodArray(vector<int>& nums) {
		int k = nums[0];
		for (int n : nums)
			k = gcd(k, n);
		return k == 1;
	}
};