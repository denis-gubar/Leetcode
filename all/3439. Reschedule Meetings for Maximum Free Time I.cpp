class Solution {
public:
    int maxFreeTime(int eventTime, int K, vector<int>& startTime, vector<int>& endTime) {
        int result = 0;
        int L = 0;
        int total = 0;
        startTime.insert(startTime.begin(), 0);
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        endTime.push_back(eventTime);
        int const N = startTime.size();
        for (int i = 0; i < N; ++i)
        {
            total -= endTime[i] - startTime[i];
            while (i + K >= L && L < N - 1)
            {
                total += endTime[L] - startTime[L];
                ++L;
            }
            result = max(result, startTime[L] - endTime[i] - total);
        }
        return result;
    }
};
