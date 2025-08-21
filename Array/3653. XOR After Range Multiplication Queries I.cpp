static int MOD = 1'000'000'007;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size();
        for (int q = 0; q < Q; ++q)
        {
            int const& L = queries[q][0];
            int const& R = queries[q][1];
            int const& K = queries[q][2];
            int const& V = queries[q][3];
            for (int i = L; i <= R; i += K)
                nums[i] = 1LL * nums[i] * V % MOD;
        }
        return accumulate(nums.begin(), nums.end(), 0, bit_xor{});
    }
};
