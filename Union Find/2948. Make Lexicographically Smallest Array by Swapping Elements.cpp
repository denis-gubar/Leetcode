class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int N = nums.size();
        vector<int> result(N);
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { nums[i], i };
        sort(P.begin(), P.end());
        P.emplace_back(1 << 30, -1);
        vector<int> Q, I;
        Q.reserve(N);
        I.reserve(N);
        for (int i = 0; i <= N; ++i)
        {
            if (!(Q.empty() || P[i].first - Q.back() <= limit))
            {
                sort(Q.begin(), Q.end());
                sort(I.begin(), I.end());
                int N = Q.size();
                for (int i = 0; i < N; ++i)
                    result[I[i]] = Q[i];
                Q.clear(); I.clear();
            }
            Q.push_back(P[i].first);
            I.push_back(P[i].second);
        }
        return result;
    }
};
