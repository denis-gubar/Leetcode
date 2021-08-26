class Solution {
public:
	int left0(int mask, int N)
	{
		mask = ((1 << N) - 1) & (~mask);
		int a = 0, b = N;
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if ((1 << m) <= mask)
				a = m;
			else
				b = m;
		}
		return a;
	}
	bool calc(int N, vector<int>::iterator first, vector<int>::iterator last, int mask, int size)
	{
		bool finished = mask + 1 == (1 << N);
		if (size == 1)
			return !finished;
		if (finished)
			return false;
		int x = left0(mask, N);
		auto first_it = lower_bound(first, last, 1 << x);
		auto last_it = lower_bound(first, last, 2 << x);
		for (auto it = first_it; it != last_it; ++it)
			if (((*it) & mask) == 0)
			{
				if (calc(N, first, first_it, mask | (*it), size - 1))
					return true;
			}
		return false;
	}
	bool makesquare(vector<int>& matchsticks) {
		int N = matchsticks.size();
		long long total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
		vector<int> A;
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			long long sum = 0;
			for (int k = 0; k < N; ++k)
				if (mask & (1 << k))
					sum += matchsticks[k];
			if (sum * 4 == total)
				A.push_back(mask);
		}
		return calc(N, A.begin(), A.end(), 0, 4);
	}
};