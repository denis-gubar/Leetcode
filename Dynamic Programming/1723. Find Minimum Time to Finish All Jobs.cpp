class Solution {
public:
	bool calc(vector<pair<int, int>>::iterator min_it, vector<pair<int, int>>::iterator it, int N, int k, int mask)
	{
		if (mask == (1 << N) - 1)
			return true;
		if (k == 0)
			return false;
		int m = mask;
        auto test_it = min_it;
		for (auto test_it = min_it; test_it != it; ++test_it)
		{
			m |= test_it->second;
			if (m == (1 << N) - 1)
				break;
		}
		if (m != (1 << N) - 1)
			return false;
		while (true)
		{
			if (it == test_it)
				break;
			--it;
			if ((mask & it->second) == 0)
				if (calc(min_it, it, N, k - 1, mask | it->second))
					return true;
		}
		return false;
	}
	int minimumTimeRequired(vector<int>& jobs, int k) {
		int N = jobs.size();
		vector<pair<int, int>> A(1 << N);
		for (int mask = 1; mask < (1 << N); ++mask)
		{
			A[mask].second = mask;
			for (int z = 0; z < N; ++z)
				if (mask & (1 << z))
					A[mask].first += jobs[z];
		}
		sort(A.begin(), A.end());
		int a = 0, b = accumulate(jobs.begin(), jobs.end(), 0);
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			auto start_it = lower_bound(A.begin(), A.end(), pair<int, int>{ m + 1, 0 });
			bool result = calc(A.begin(), start_it, N, k, 0);
			if (result)
				b = m;
			else
				a = m;
		}
		return b;
	}
};