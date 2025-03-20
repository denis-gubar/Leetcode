class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int const N = nums.size(), Q = queries.size();
        vector<int> result(Q, -1);
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for (int q = 0; q < Q; ++q)
        {
            int const& pos = queries[q];
            int const& j = nums[pos];
            if (M[j].size() == 1)
                continue;
            auto it = lower_bound(M[j].begin(), M[j].end(), pos);
            auto nit = next(it);
            if (nit == M[j].end())
                nit = M[j].begin();
            int delta = abs(*it - *nit);
            result[q] = min(delta, N - delta);
            if (it == M[j].begin())
                nit = prev(M[j].end());
            else
                nit = prev(it);
            delta = abs(*it - *nit);
            result[q] = min(result[q], min(delta, N - delta));
        }
        return result;
    }
};
