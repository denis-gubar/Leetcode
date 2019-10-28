/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	enum EventType
	{
		end = -1,
		start = 1,
	};
	int minMeetingRooms(vector<Interval>& intervals) {
		int result = 0;
		vector<pair<int, int>> events;
		for (const Interval& interval : intervals)
		{
			events.push_back({ interval.start, EventType::start });
			events.push_back({ interval.end, EventType::end });
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