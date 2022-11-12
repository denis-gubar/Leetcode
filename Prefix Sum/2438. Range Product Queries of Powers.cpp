class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        constexpr int MOD = 1'000'000'007;
        vector<int> powers;
        for (int k = 0; k < 31; ++k)
            if (n & (1 << k))
                powers.push_back(1 << k);
        for (int j = 0; j < queries.size(); ++j)
        {
            int const& left = queries[j][0];
            int const& right = queries[j][1];
            long long x = 1;
            for (int k = left; k <= right; ++k)
                x = x * powers[k] % MOD;
            result.push_back(x);
        }
        return result;
    }
};
