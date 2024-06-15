class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size();
        int Q = queries.size();
        vector<bool> result(Q);
        set<pair<int, int>> S;
        int prev = 0;
        for (int i = 1; i <= N; ++i)
            if (i == N || nums[i] % 2 == nums[i - 1] % 2)
                S.insert({ prev, i - 1 }), prev = i;
        for (int q = 0; q < Q; ++q)
        {
            int const& a = queries[q][0];
            int const& b = queries[q][1];
            auto it = S.lower_bound({ a, 1 << 20 });
            if (it == S.begin())
                continue;
            --it;
            if (it->second >= b)
                result[q] = true;
        }
        return result;
    }
};
