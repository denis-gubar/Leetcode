static int const MOD = 1'000'000'007;
static int F[27];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int x = 1; x <= 26; ++x)
            F[x] = 1LL * x * F[x - 1] % MOD;
    }
}
class Solution {
public: 
    int power(int x, int n)
    {
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
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        init();
        int N = s.size();
        int result = 1;
        map<char, int> M;
        for (char c : s)
            ++M[c];
        if (M.size() < k)
            return 0;
        vector<pair<int, char>> P;
        for (auto [key, value] : M)
            P.emplace_back(-value, key);
        sort(P.begin(), P.end());
        int balance = 0;
        int lastKey = -1;
        for (auto [key, value] : P)
        {
            if (balance >= k && key != lastKey)
                break;
            ++balance;
            lastKey = key;
        }
        int i = 0;
        while (true)
        {
            if (P[i].first == lastKey)
                break;
            result = 1LL * result * (-P[i].first) % MOD;
            ++i;
        }
        if (balance >= k)
        {
            int rest = balance - i;
            result = 1LL * result * C(balance - i, k - i) % MOD * power(-lastKey, k - i) % MOD;
        }
        return result;
    }
};
