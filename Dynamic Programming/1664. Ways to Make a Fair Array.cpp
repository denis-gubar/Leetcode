class Solution {
public:
	int waysToMakeFair(vector<int>& nums) {
		long long odd = 0, even = 0;
		int N = nums.size();
		for (int i = 0; i < N; i += 2)
			odd += nums[i];
		for (int i = 1; i < N; i += 2)
			even += nums[i];
		int result = 0;
		long long O = 0, E = 0;
		for (int i = 0; i < N; ++i)
		{
			int x = nums[i];
			if (i % 2 == 0)
				odd -= x;
			else
				even -= x;
			if (odd + E == even + O)
				++result;
			if (i % 2 == 0)
				O += x;
			else
				E += x;
		}
		return result;
	}
};