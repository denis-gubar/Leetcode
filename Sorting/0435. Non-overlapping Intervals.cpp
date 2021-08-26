class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return 0;
		sort(intervals.begin(), intervals.end(), [](vector<int> const& a, vector<int> const& b)
			{
				return a[1] < b[1];
			}
		);
        int result = -1;
        int left = intervals[0][1];
		for (vector<int> const& interval : intervals)
		{
			if (left > interval[0])
                ++result;
            else
                left = interval[1];
		}
		return result;
	}
};