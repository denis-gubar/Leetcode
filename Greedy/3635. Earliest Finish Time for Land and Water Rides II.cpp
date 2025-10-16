class Solution {
public:
    int f(int time, vector<int> const& startTime, vector<int> const& durationTime)
    {
        int result = 1 << 30;
        int const N = startTime.size();
        for (int i = 0; i < N; ++i)
            if (startTime[i] > time)
                result = min(result, startTime[i] + durationTime[i]);
            else
                result = min(result, time + durationTime[i]);
        return result;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int L = f(0, landStartTime, landDuration);
        int W = f(0, waterStartTime, waterDuration);
        return min(f(W, landStartTime, landDuration), f(L, waterStartTime, waterDuration));
    }
};
