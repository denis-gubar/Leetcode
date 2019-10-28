class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<vector<int>> events;
		for (vector<int> const& trip : trips)
		{
			events.push_back({ trip[1], 1, trip[0] });
			events.push_back({ trip[2], -1, trip[0] });
		}
		sort(events.begin(), events.end());
		int balance = 0;
		for (vector<int> const& event : events)
		{
			balance += event[1] * event[2];
			if (balance > capacity)
				return false;
		}
		return true;
	}
};