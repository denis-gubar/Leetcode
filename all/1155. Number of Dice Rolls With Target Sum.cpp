static int F[1001][31];
class Solution {
public:
    int numRollsToTarget(int N, int K, int target) {
        int const MOD = 1'000'000'007;
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for (int i = 0; i < N * K; ++i)
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= K; ++k)
                    F[i + k][j + 1] = (F[i + k][j + 1] + F[i][j]) % MOD;
        return F[target][N];
    }
};
