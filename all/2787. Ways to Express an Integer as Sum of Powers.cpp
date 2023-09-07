int const MOD = 1'000'000'007;
int static power(int n, int x)
{
    int result = n;
    for (int k = 1; k < x; ++k)
    {
        result *= n;
        if (result > 301)
            return 301;
    }
    return result;
}
int static F[301][301];
int static results[301][6];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(results, 0, sizeof(results));
        for (int x = 1; x <= 5; ++x)
        {
            memset(F, -1, sizeof(F));
            F[0][0] = 1;
            vector<int> NI(304);
            for (int i = 1; i <= 303; ++i)
                NI[i] = power(i, x);
            for (int sum = 0; sum < 300; ++sum)
                for (int i = 0; NI[i + 1] + sum <= 300; ++i)
                    if (F[sum][i] >= 0)
                    {
                        for (int j = i + 1; NI[j] + sum <= 300; ++j)
                            if (F[NI[j] + sum][j] < 0)
                                F[NI[j] + sum][j] = F[sum][i];
                            else
                            {
                                F[NI[j] + sum][j] += F[sum][i];
                                F[NI[j] + sum][j] %= MOD;
                            }
                    }
            for(int n = 1; n <= 300; ++n)
                for (int i = 1; i <= 300; ++i)
                    if (F[n][i] > 0)
                    {
                        results[n][x] += F[n][i];
                        results[n][x] %= MOD;
                    }
        }
    }
}

class Solution {
public:
    int numberOfWays(int n, int x) {
        init();        
        return results[n][x];
    }
};
