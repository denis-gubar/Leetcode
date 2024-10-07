static bool isInit = false;
static int const MOD = 1'337;
static int F[MOD][11];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        for (int i = 0; i < MOD; ++i)
        {
            F[i][0] = 1;
            for (int p = 1; p <= 10; ++p)
                F[i][p] = F[i][p - 1] * i % MOD;
        }            
    }
}
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        init();
        a %= MOD;
        if (a == 1)
            return 1;
        if (b == vector<int>{0})
            return 1;
        int result = 1;
        for (int x : b)
            result = F[result][10] * F[a][x] % MOD;
        return result;
    }
};
