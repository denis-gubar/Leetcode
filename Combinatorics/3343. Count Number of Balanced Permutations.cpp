static int const MOD = 1'000'000'007;
static int F[41][361];
static unsigned char D[10];
static int fact[81];
static int invFact[81];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(fact, 0, sizeof(fact));
        memset(invFact, 0, sizeof(invFact));
        int inv[81];
        inv[1] = fact[0] = invFact[0] = fact[1] = invFact[1] = 1;
        for (int x = 2; x <= 80; ++x)
        {
            fact[x] = 1LL * fact[x - 1] * x % MOD;
            inv[x] = MOD - 1LL * MOD / x * inv[MOD % x] % MOD;
            invFact[x] = 1LL * invFact[x - 1] * inv[x] % MOD;
        }
    }
}
class Solution {
public:
    int countBalancedPermutations(string num) {
        init();
        int const N = num.size(), N2 = N / 2;
        memset(D, 0, sizeof(D));
        int total = 0;
        for (char c : num)
        {
            int const x = c - '0';
            ++D[x], total += x;
        }
        if (total % 2)
            return 0;
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for (char c : num)
        {
            int const d = c - '0';
            for (int i = N2; i > 0; --i)
                for (int j = total / 2; j >= d; --j)
                    F[i][j] = (F[i][j] + F[i - 1][j - d]) % MOD;
        }
        long long result = 1LL * F[N2][total / 2] * fact[N2] % MOD * fact[N - N2] % MOD;
        for (int d = 0; d < 10; ++d)
            result = result * invFact[D[d]] % MOD;
        return result;
    }
};