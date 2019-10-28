class Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> result;
		vector<pair<int, pair<int, int>>> events;
		for (vector<int> const& booking : bookings)
		{
			events.push_back({ booking[0], {1, booking[2]} });
			events.push_back({ booking[1] + 1, {-1, booking[2]} });
		}
		sort(events.begin(), events.end());
		int balance = 0, flight = 1;
		for (auto e : events)
		{
            while(flight < e.first)
            {
                result.push_back(balance);
                ++flight;
            }
			balance += e.second.first * e.second.second;
		}
        while(flight <= n)
        {
            result.push_back(0);
            ++flight;
        }
		return result;
	}
};