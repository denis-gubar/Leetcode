static int F[59];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[2] = 1;
        for (int x = 3; x < 59; ++x)
            for (int a = 1; a + a <= x; ++a)
                F[x] = max(F[x], max(F[a], a) * max(F[x - a], x - a));
    }
}
class Solution {
public:
    int integerBreak(int n) {
        init();
        return F[n];
    }
};
