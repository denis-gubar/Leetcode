class Solution {
public:
	int minimumEffort(vector<vector<int>>& tasks) {
		sort(tasks.begin(), tasks.end(), [](vector<int> const& a, vector<int> const& b)
			{
				if (a[1] - a[0] != b[1] - b[0])
					return a[1] - a[0] > b[1] - b[0];
				return a[0] > b[0];
			});
		int a = -1, b = 0, N = tasks.size();
		for (int i = 0; i < N; ++i)
			a += tasks[i][0], b += tasks[i][1];
		auto calc = [&tasks, N](int x)
		{
			for (int i = 0; i < N; ++i)
				if (x < tasks[i][1])
					return false;
				else
					x -= tasks[i][0];
			return true;
		};
		while (a + 1 < b)
		{
			int m = (a + b) / 2;
			if (calc(m))
				b = m;
			else
				a = m;
		}
		return b;
	}
};