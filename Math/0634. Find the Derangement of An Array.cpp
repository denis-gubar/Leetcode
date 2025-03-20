static int F[1'000'001];
static bool isInit = false;
static int const MOD = 1'000'000'007;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        F[1] = 0, F[2] = 1;
        for (int i = 3; i <= 1'000'000; ++i)
            F[i] = 1LL * (i - 1) * (F[i - 2] + F[i - 1]) % MOD;
    }
}
class Solution {
public:
    int findDerangement(int n) {
        init();
        return F[n];
    }
};
