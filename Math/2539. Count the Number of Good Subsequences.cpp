static int const MOD = 1'000'000'007;
static int const MAX_N = 10'000;
static int fact[MAX_N + 1];
static int invFact[MAX_N + 1];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(fact, 0, sizeof(fact));
        memset(invFact, 0, sizeof(invFact));
        int inv[MAX_N + 1];
        inv[1] = fact[0] = invFact[0] = fact[1] = invFact[1] = 1;
        for (int x = 2; x <= MAX_N; ++x)
        {
            fact[x] = 1LL * fact[x - 1] * x % MOD;
            inv[x] = MOD - 1LL * MOD / x * inv[MOD % x] % MOD;
            invFact[x] = 1LL * invFact[x - 1] * inv[x] % MOD;
        }
    }
}
class Solution {
public:
    int countGoodSubsequences(string s) {
        init();
        long long result = 0;
        vector<int> M(26);
        for (char c : s)
            ++M[c - 'a'];
        sort(M.begin(), M.end(), greater{});
        M.resize(remove(M.begin(), M.end(), 0) - M.begin());
        int prev = 0;
        while (!M.empty())
        {
            int const N = M.size();
            int k = prev + 1;
            prev = M.back();
            for (; k <= prev; ++k)
            {
                int P = 1;
                for (int x : M)
                    P = P * (1LL * fact[x] % MOD * invFact[x - k] % MOD * invFact[k] % MOD + 1) % MOD;
                P = (P + (MOD - 1)) % MOD;
                result += P;
            }
            while (!M.empty() && M.back() == prev)
                M.pop_back();
        }
        return result % MOD;
    }
};
