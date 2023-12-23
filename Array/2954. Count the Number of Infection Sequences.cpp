static int const MOD = 1'000'000'007;
static int F[100'001];
static int fact[200'001];
static bool isInit = false;
static int power(int x, int n)
{
    if (n == 0)
        return 1;
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
static int div(int x)
{
    return power(x, MOD - 2);
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        memset(fact, 0, sizeof(fact));
        F[0] = F[1] = fact[0] = fact[1] = 1;
        for (int x = 2; x <= 100'000; ++x)
            F[x] = (F[x - 1] + F[x - 1]) % MOD;
        for (int x = 2; x <= 200'000; ++x)
            fact[x] = 1LL * fact[x - 1] * x % MOD;
    }
}
class Solution {
public:
    int numberOfSequence(int N, vector<int>& sick) {
        init();
        int M = sick.size();
        if ((sick.back() + 1 == M) || sick[0] + M == N)
            return 1;
        long long a = 0, b = 1, c = 1;
        auto add = [&a, &b, &c](int x)
            {
                a += x, b = b * fact[x] % MOD, c = c * F[x] % MOD;
            };
        if (sick[0] > 0)
            a += sick[0], b = b * fact[sick[0]] % MOD;
        if (sick.back() < N - 1)
            a += N - 1 - sick.back(), b = b * fact[N - 1 - sick.back()] % MOD;
        for (int i = 1; i < M; ++i)
            if (sick[i] - sick[i - 1] > 1)
                add(sick[i] - sick[i - 1] - 1);
        return 1LL * c * fact[a] % MOD * div(b) % MOD;
    }
};

