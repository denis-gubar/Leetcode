class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int N = nums.size();
		int a = 0, b = N - 1;
		auto get = [&nums, N](int i)
		{
			if (i >= 0 && i < N)
				return 1LL * nums[i];
			return -(1LL << 40);
		};
		auto check = [&get](int i)
		{
			return pair<bool, bool>{get(i - 1) < get(i), get(i) > get(i + 1)};
		};
		auto A = check(a);
		if (A.first && A.second)
			return a;
		auto B = check(b);
		if (B.first && B.second)
			return b;
		while (true)
		{
			int m = (a + b) / 2;
			auto M = check(m);
			if (M.first && M.second)
				return m;
			if (M.first)
				a = m;
			else
				b = m;
		}
		return -1;
	}
};