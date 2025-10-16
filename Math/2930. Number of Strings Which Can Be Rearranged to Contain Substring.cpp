static int const MOD = 1'000'000'007;
static int F[100'001][16];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for (int x = 1; x <= 100'000; ++x)
            for (int mask = 0; mask < 16; ++mask)
            {
                F[x][mask | (1 << 0)] = (F[x - 1][mask] + F[x][mask | (1 << 0)]) % MOD;
                F[x][mask | (1 << 1)] = (F[x - 1][mask] + F[x][mask | (1 << 1)]) % MOD;
                if (mask & (1 << 2))
                    F[x][mask | (1 << 3)] = (F[x - 1][mask] + F[x][mask | (1 << 3)]) % MOD;
                else
                    F[x][mask | (1 << 2)] = (F[x - 1][mask] + F[x][mask | (1 << 2)]) % MOD;
                F[x][mask] = (1LL * F[x - 1][mask] * 23 + F[x][mask]) % MOD;
            }
    }
}
class Solution {
public:
    int stringCount(int N) {
        init();
        return F[N][15];
    }
};
