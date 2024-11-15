static int const MOD = 1'000'000'007;
static int G[801];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(G, 0, sizeof(G));
        auto bitCount = [](int x)
            {
                int result = 0;
                while (x > 0)
                    ++result, x &= x - 1;
                return result;
            };
        for (int i = 2; i <= 800; ++i)
        {
            int x = bitCount(i);
            G[i] = 1;
            while (x > 1)
                ++G[i], x = bitCount(x);
        }
    }
}
static int F[801][801][2];
class Solution {
public:
    int countKReducibleNumbers(string s, int K) {
        init();
        int const N = s.size();
        memset(F, 0, sizeof(F));
        F[0][0][true] = 1;
        auto add = [](int& x, int y) -> void
            {
                x += y;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0; i < N; ++i)
            for(int sum = 0; sum <= i; ++sum)
                for (int isB = 0, b = s[i] - '0'; isB < 2; ++isB)
                    if (F[i][sum][isB])
                        for (int d = 0; d < 2; ++d)
                            if (!isB || d <= b)
                                add(F[i + 1][sum + d][isB && d == b], F[i][sum][isB]);
        long long result = 0;
        for (int sum = 1; sum <= N; ++sum)
            if (G[sum] < K)
                result += F[N][sum][false];
        return result % MOD;
    }
};
