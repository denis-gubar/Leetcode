class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int result = 0;
        sort(meetings.begin(), meetings.end(), [](vector<int> const& a, vector<int> const& b)
            {
                return a[0] < b[0];
            });
        int last = 0;
        int N = meetings.size();
        for (int i = 0; i < N; ++i)
        {
            int const& start = meetings[i][0];
            int const& end = meetings[i][1];
            if (start > last)
                result += start - last - 1;
            last = max(last, end);
        }
        if (days > last)
            result += days - last;
        return result;
    }
};
