int static F[1'001][1'001];
static bool isInit = false;
static int const MOD = 1'000'000'007;
static int calc(int n, int k)
{
    if (n == 1 && k == 0)
        return 1;
    if (k < 0 || k > n * (n - 1) / 2)
        return 0;
    if (F[n][k] == -1)
        F[n][k] = (0LL + calc(n, k - 1) + calc(n - 1, k) - calc(n - 1, k - n) + MOD) % MOD;
    return F[n][k];
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, -1, sizeof(F));
        calc(1'000, 1'000);
    }
}
class Solution {
public:
    int kInversePairs(int n, int k) {
        init();
        return calc(n, k);
    }
};