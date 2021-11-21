class Solution {
public:
	int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
		sort(tasks.begin(), tasks.end());
		sort(workers.begin(), workers.end());
		int T = tasks.size(), W = workers.size();
		int a = 0, b = T + 10;
		if (strength == 0)
			pills = 0;
		auto calc = [&tasks, &workers, T, W, pills, strength](int m)
		{
			if (m > W || m > T)
				return false;
			int PILLS = pills;
			multiset<int> S;
			for (int i = 0, j = W - m; i < m; ++i, ++j)
				S.insert( workers[j] );
			for (int i = m - 1; i >= 0; --i)
			{
				auto it = prev(S.end());
				if (*it < tasks[i])
				{
					if (PILLS == 0)
						return false;
					--PILLS;
					auto next = S.lower_bound(tasks[i] - strength);
					if (next == S.end())
						return false;
					S.erase(next);
				}
				else
					S.erase(it);
			}
			return true;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				a = m;
			else
				b = m;
		}
		return a;
	}
};