class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int result = events[0][0];
        int best = events[0][1];
        int const N = events.size();
        for (int i = 1; i < N; ++i)
            if (events[i][1] - events[i - 1][1] > best)
                best = events[i][1] - events[i - 1][1], result = events[i][0];
            else if (events[i][1] - events[i - 1][1] == best && result > events[i][0])
                result = events[i][0];
        return result;
    }
};
