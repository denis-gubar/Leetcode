class Solution {
public:
	int maxValue(vector<vector<int>>& events, int k) {
		int result = 0;
		int N = events.size();
		set<int> S;
		for (int i = 0; i < N; ++i)
		{
			S.insert(events[i][0]);
			S.insert(events[i][1]);
		}
		unordered_map<int, int> keys;
		for (auto it = S.begin(); it != S.end(); ++it)
			keys[*it] = keys.size() + 1;
		for (int i = 0; i < N; ++i)
		{
			events[i][0] = keys[events[i][0]];
			events[i][1] = keys[events[i][1]];
		}

		sort(events.begin(), events.end(),
			[](vector<int> const& a, vector<int> const& b)
			{
				return a[1] < b[1];
			});

		vector<vector<int>> F({ { 0 } });
		int last = 0;
		for (int i = 1; i <= keys.size(); ++i)
		{
			while (last < N && events[last][1] == i)
			{
				while (F.size() <= i)
					F.push_back(F.back());
				const int& start = events[last][0];
				const int& end = events[last][1];
				const int& value = events[last][2];
				for (int j = 0; j < F[start - 1].size() && j < k; ++j)
				{
					if (F[end].size() == j + 1)
						F[end].push_back(F[start - 1][j] + value);
					else
						F[end][j + 1] = max(F[end][j + 1], F[start - 1][j] + value);
					result = max(result, F[end][j + 1]);
				}
				++last;
			}
		}
		return result;
	}
};