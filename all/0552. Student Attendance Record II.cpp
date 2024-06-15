static int const MOD = 1'000'000'007;
static int F[100'001][3][4];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[0][0][0] = 1;
        for (int i = 0; i < 100'000; ++i)
            for(int j = 0; j < 2; ++j)
                for (int k = 0; k < 3; ++k)
                {
                    F[i + 1][j][0] = (F[i + 1][j][0] + F[i][j][k]) % MOD;
                    F[i + 1][j + 1][0] = (F[i + 1][j + 1][0] + F[i][j][k]) % MOD;
                    F[i + 1][j][k + 1] = (F[i + 1][j][k + 1] + F[i][j][k]) % MOD;
                }
    }
}
class Solution {
public:
    int checkRecord(int n) {
        init();
        long long result = 0;
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 3; ++k)
                result += F[n][j][k];
        return result % MOD;
    }
};
