static int const MOD = 1'000'000'007;
static int F[1'001][1'001][2];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[0][0][0] = 1;
        auto add = [](int& x, int y) -> void
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for(int i = 0; i < 1'000; ++i)
            for (int k = 0; k <= i; ++k)
                for(int flag = 0; flag < 2; ++flag)
                    if (F[i][k][flag])
                    {
                        add(F[i + 1][k][0], F[i][k][flag]);
                        if (flag == 1)
                            add(F[i + 1][k][flag], F[i][k][flag]);
                        add(F[i + 1][k + 1][1], F[i][k][flag]);
                    }
    }
}
class Solution {
public:
    int numberOfSets(int N, int K) {
        init();
        --N;
        return (F[N][K][0] + F[N][K][1]) % MOD;
    }
};
