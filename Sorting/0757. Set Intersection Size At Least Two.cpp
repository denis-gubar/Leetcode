class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int result = 0;
        int const N = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> const& a, vector<int> const& b)
            {
                if (a[1] != b[1])
                    return a[1] < b[1];
                return a[0] < b[0];
            }
        );
        set<int> S;
        S.insert(-2), S.insert(-1);
        for (int i = 0; i < N; ++i)
        {
            int const& START = intervals[i][0];
            int const& END = intervals[i][1];
            if (START > *S.rbegin())
                S.clear(), S.insert(END - 1), S.insert(END), result += 2;
            else if (START > *S.begin())
                S.erase(S.begin()), S.insert(END - (*S.begin() == END)), ++result;
        }
        return result;
    }
};
