static int const MOD = 1'000'000'007;
static bool isInit = false;
static int F[1'001][1'001];
static int fact[1'001];
static int comb[1'001][1'001];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        static constexpr int N = 1'000;
        for (int i = 0; i <= N; ++i)
            comb[i][0] = comb[i][i] = 1;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j < i; ++j)
            {
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
                if (comb[i][j] >= MOD)
                    comb[i][j] -= MOD;
            }
        fact[0] = 1;
        for (int i = 1; i <= N; ++i)
            fact[i] = 1LL * fact[i - 1] * i % MOD;
        memset(F, -1, sizeof(F));
    }
}
static int C(int n, int k)
{
    constexpr int N = 1'000;
    return n >= k && k >= 0 && n <= N ? comb[n][k] : 0;
}
class Solution {
public:
    int calc(int N, int K)
    {
        if (N <= 0)
            return 0;
        if (K == 1)
            return fact[N - 1];
        int& result = F[N][K];
        if (result < 0)
        {
            result = 0;
            for (int pos = 0; pos < N; ++pos)
                result = (1LL * calc(pos, K - 1) * C(N - 1, N - 1 - pos) % MOD * fact[N - 1 - pos] + result) % MOD;
        }
        return result;
    }
    int rearrangeSticks(int n, int k) {
        init();
        return calc(n, k);
    }
};
