class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> const& a, vector<int> const& b)
            {
                if (a[0] != b[0])
                    return a[0] < b[0];
                return a[1] > b[1];
            });
        int const N = envelopes.size();
        vector<int> M;
        M.reserve(N);
        for (int i = 0; i < N; ++i)
        {
            int const& y = envelopes[i][1];
            auto it = lower_bound(M.begin(), M.end(), y);
            if (it == M.end())
                M.push_back(y);
            else
                *it = y;
        }
        return M.size();
    }
};
