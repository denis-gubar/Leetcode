class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		vector<pair<int, pair<int, int>>> E;
        E.reserve(events.size() * 2);
		int result = 0;
		for (vector<int> const& ev : events)
		{
			int const& startTime = ev[0];
			int const& endTime = ev[1];
			int const& value = ev[2];
			E.push_back({ endTime + 1, {-1, value} });
			E.push_back({ startTime, {1, value} });
		}
		sort(E.begin(), E.end());
		int best = 0;
		int N = E.size();
		for (int i = 0; i < N; ++i)
		{
			int const& type = E[i].second.first;
			int const& time = E[i].first;
			int const& value = E[i].second.second;
			if (type == 1)
				result = max(result, best + value);
			else
				best = max(best, value);
		}
		return result;
	}
};