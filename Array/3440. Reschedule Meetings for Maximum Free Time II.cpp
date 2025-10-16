class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int result = 0;
        startTime.insert(startTime.begin(), 0);
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(), 0);
        endTime.push_back(eventTime);
        int const N = startTime.size();
        vector<int> L(N), R(N);
        for (int i = 1; i < N; ++i)
            L[i] = max(L[i - 1], startTime[i] - endTime[i - 1]);
        for (int i = N - 2; i >= 0; --i)
            R[i] = max(R[i + 1], startTime[i + 1] - endTime[i]);

        for (int i = 1; i < N - 1; ++i)
        {
            int const length = endTime[i] - startTime[i];
            if (L[i - 1] >= length || R[i + 1] >= length)
                result = max(result, startTime[i + 1] - endTime[i - 1]);
            else
                result = max(result, startTime[i + 1] - endTime[i - 1] - length);
        }
        return result;
    }
};
