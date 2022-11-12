class Solution {
public:
    int numRollsToTarget(int N, int K, int target) {
        constexpr int MOD = 1'000'000'007;
        vector<long long> F(target + 1);
        F[0] = 1;
        for (int n = 0; n < N; ++n)
        {
            for (int i = min(target, n * K + K); i > 0; --i)
            {
                F[i] = 0;
                for (int j = 1; j <= min(i, K); ++j)
                    F[i] += F[i - j];
                F[i] %= MOD;
            }
            F[0] = 0;
        }
        return F[target];
    }
};
