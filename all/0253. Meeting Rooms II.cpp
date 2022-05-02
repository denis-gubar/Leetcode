class Solution {
public:
	enum EventType
	{
		end = -1,
		start = 1,
	};
    int minMeetingRooms(vector<vector<int>>& intervals) {
		int result = 0;
		vector<pair<int, int>> events;
		for (vector<int> const& interval : intervals)
		{
			events.push_back({ interval[0], EventType::start });
			events.push_back({ interval[1], EventType::end });
		}
		sort(events.begin(), events.end());
		int balance = 0;
		for (pair<int, int> event : events)
		{
			balance += event.second;
			result = max(result, balance);
		}
		return result;        
    }
};