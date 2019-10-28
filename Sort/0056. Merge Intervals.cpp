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
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		vector<pair<int, int>> events;
		for (const Interval& i : intervals)
		{
			events.push_back({ i.start, -1 });
			events.push_back({ i.end, 1 });
		}
		sort(events.begin(), events.end());
		int balance = 0;
		int start = 0;
		for (pair<int, int> e : events)
		{
			if (e.second == 1 && --balance == 0)
				result.push_back(Interval(start, e.first));
			else if (e.second == -1 && ++balance == 1)
				start = e.first;
		}
		return result;
	}
};