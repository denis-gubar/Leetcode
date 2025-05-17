static int const MAX_N = 10'000;
static char F[MAX_N + 1];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, -1, sizeof(F));
        F[0] = 0;
        for (int k = 1; k < 5; ++k)
            for (int i = MAX_N; i > 0; --i)
                if (F[i] < 0)
                    for (int j = 1; j * j <= i; ++j)
                        if (F[i - j * j] >= 0)
                        {
                            F[i] = F[i - j * j] + 1;
                            break;
                        }
    }
}
class Solution {
public:
    int numSquares(int N) {
        init();
        return F[N];
    }
};
