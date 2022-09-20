class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {        
        int N = intervals.size();
        sort(intervals.begin(), intervals.end());
        multiset<int> S;
        for (int i = 0; i < N; ++i)
        {
            int const& left = intervals[i][0];
            int const& right = intervals[i][1];
            if (!S.empty())
            {
                if (*S.begin() <= left)
                    S.erase(S.begin());
            }
            S.insert(right + 1);
        }
        return S.size();
    }
};
