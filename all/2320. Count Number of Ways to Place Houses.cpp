long long F[20'001][2][2];
class Solution {
public:
    int countHousePlacements(int N) {
        constexpr int MOD = 1'000'000'007;
        long long result = 0;
        F[0][0][0] = 1;
        for (int i = 0; i < N; ++i)
        {
            F[i + 1][0][0] = (F[i][0][0] + F[i][0][1] + F[i][1][0] + F[i][1][1]) % MOD;
            F[i + 1][0][1] = (F[i][0][0] + F[i][1][0]) % MOD;
            F[i + 1][1][0] = (F[i][0][0] + F[i][0][1]) % MOD;
            F[i + 1][1][1] = (F[i][0][0]) % MOD;
        }
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                result += F[N][i][j];
        return result % MOD;
    }
};
