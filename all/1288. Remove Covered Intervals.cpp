class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int result = intervals.size();
		sort(intervals.begin(), intervals.end(),
			[](vector<int>& a, vector<int>& b)
			{
				if (a[0] != b[0])
					return a[0] < b[0];
				return b[1] < a[1];
			}
		);
		int right = intervals[0][1];
		for (int i = 1; i < intervals.size(); ++i)
			if (intervals[i][1] <= right)
				--result;
			else
				right = intervals[i][1];
		return result;
	}
};