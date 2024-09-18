class Solution {
public:
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int result = 0;
        int N = startTime.size();
		vector<int> times;
        times.reserve(2 * N);
		for (int i : startTime)
			times.push_back(i);
		for (int i : endTime)
			times.push_back(i);
		sort(times.begin(), times.end());
		times.erase(unique(times.begin(), times.end()), times.end());
		unordered_map<int, int> invTimes;
		for (int i = 0; i < times.size(); ++i)
			invTimes[times[i]] = i;
		vector<vector<int>> intervals;
        intervals.reserve(N);
		for (int i = 0; i < startTime.size(); ++i)
			intervals.push_back({ invTimes[endTime[i]], invTimes[startTime[i]], i });
		sort(intervals.begin(), intervals.end());
		vector<int> maxProfit(times.size() + 1);
		int last = 0;
		for (int i = 0; i < intervals.size(); ++i)
		{
			while (last < intervals[i][0] + 1)
			{
				maxProfit[last + 1] = maxProfit[last];
				++last;
			}
			maxProfit[intervals[i][0] + 1] = max(maxProfit[intervals[i][0] + 1],
				maxProfit[intervals[i][1] + 1] + profit[intervals[i][2]]);
		}
		return maxProfit.back();
	}
};