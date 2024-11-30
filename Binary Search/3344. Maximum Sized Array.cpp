static bool isInit = false;
static long long F[2000];
static int MAXN = 0;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        F[0] = -1;
        int x = 0;
        for (MAXN = 1; F[MAXN - 1] < 1'000'000'000'000'000LL; ++MAXN)
        {
            for (int j = 0; j < MAXN - 1; ++j)
                x += 2 * ((MAXN - 1) | j);
            x += (MAXN - 1) | (MAXN - 1);
            F[MAXN] = 1LL * MAXN * (MAXN - 1) / 2 * x;
        }
    }
}
class Solution {
public:
    int maxSizedArray(long long s) {
        init();
        return (upper_bound(&F[0], &F[0] + MAXN, s) - &F[0]) - 1;
    }
};
