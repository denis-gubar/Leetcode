class Solution {
public:
	int sum(int x)
	{
		int result = 0;
		while (x)
		{
			result += x % 10;
			x /= 10;
		}
		return result;
	}
	int countLargestGroup(int n) {
		map<int, int> M;
		for (int i = 1; i <= n; ++i)
			++M[sum(i)];
		int best = 0;
		for (auto m : M)
			if (m.second > best)
				best = m.second;
		int result = 0;
		for (auto m : M)
			result += m.second == best;
		return result;
	}
};