int static F[14][1 << 14];
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int const MOD = 1'000'000'007;
        int N = nums.size();
        long long result = 0;
        memset(F, 0, sizeof(F));
        for (int j = 0; j < N; ++j)
            F[j][1 << j] = 1;
        for(int mask = 0; mask < (1 << N); ++mask)
            for (int j = 0; j < N; ++j)
                if (F[j][mask])
                {
                    for (int k = 0; k < N; ++k)
                        if ((mask & (1 << k)) == 0 && (nums[k] % nums[j] == 0 || nums[j] % nums[k] == 0))
                        {
                            F[k][mask | (1 << k)] += F[j][mask];
                            F[k][mask | (1 << k)] %= MOD;
                        }
                }
        for (int j = 0; j < N; ++j)
            result += F[j][(1 << N) - 1];
        return result % MOD;
    }
};
