static int const MOD = 1'000'000'007;
static int F[100'001];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        F[0] = 1;
        for (int x = 1; x <= 100'000; ++x)
            F[x] = 1LL * x * F[x - 1] % MOD;
    }
}
class Solution {
public:
    int power(int x, int n)
    {
        if (n == 0)
            return 1;
        if (x == 0)
            return 0;
        if (n == 1)
            return x;
        long long result = x;
        long long extra = 1;
        while (n > 1)
        {
            if (n % 2)
            {
                extra *= result;
                extra %= MOD;
            }
            result *= result;
            result %= MOD;
            n /= 2;
        }
        return result * extra % MOD;
    }
    int div(int x)
    {
        return power(x, MOD - 2);
    }
    int C(int N, int K)
    {
        return 1LL * F[N] * div(F[K]) % MOD * div(F[N - K]) % MOD;
    }
    int countGoodArrays(int N, int M, int K) {
        init();
        if (K == 0 && M == 1)
            return N == 1;
        long long result = 1LL * M * power(M - 1, N - 1 - K) % MOD;
        result = result * C(N - 1, K) % MOD;
        return result;
    }
};
