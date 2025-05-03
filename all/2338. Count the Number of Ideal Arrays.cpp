static int const MOD = 1'000'000'007;
static int C[10'101][14];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(C, 0, sizeof(C));
        C[0][0] = 1;
        for (int n = 1; n < 10'101; ++n)
        {
            C[n][0] = 1;
            for (int k = 1; k < 14; ++k)
                C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
        }
    }
}
class Solution {
public:
    int idealArrays(int N, int M) {
        init();
        long long result = 0;
        for (int i = 1; i <= M; ++i)
        {
            long long current = 1;
            int x = i;
            while (x > 1)
            {
                for(int k = 2; k <= x; ++k)
                    if (x % k == 0)
                    {
                        int count = 0;
                        while (x % k == 0)
                        {
                            ++count;
                            x /= k;
                        }
                        current = current * C[N + count - 1][count] % MOD;
                    }
            }
            result += current;
        }
        return result % MOD;
    }
};
