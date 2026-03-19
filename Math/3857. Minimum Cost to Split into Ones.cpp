static int const MAX_N = 500;
static int F[MAX_N + 1];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, -1, sizeof(F));
        F[0] = F[1] = 0; F[2] = 1;
        for (int x = 3; x <= 500; ++x)
            F[x] = F[x / 2] + F[(x + 1) / 2] + (x / 2) * ((x + 1) / 2);
    }
}
class Solution {
public:
    int minCost(int N) {
        init();
        return F[N];
    }
};
