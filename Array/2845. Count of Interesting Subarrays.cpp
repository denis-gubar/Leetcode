class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int MOD, int K) {
        long long result = 0;
        int const N = nums.size();
        unordered_map<int, int> M;
        int count = 0;
        M[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            count += (nums[i] % MOD == K);
            count %= MOD;
            result += M[(MOD - K + count) % MOD];
            ++M[count];
        }
        return result;
    }
};
