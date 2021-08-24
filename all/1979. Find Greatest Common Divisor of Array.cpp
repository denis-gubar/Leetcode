class Solution {
public:
	template<typename T> T gcd(T a, T b)
	{
		while (a && b) if (a > b) a %= b; else b %= a; return a + b;
	}
	int findGCD(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return gcd(nums[0], nums.back());
	}
};