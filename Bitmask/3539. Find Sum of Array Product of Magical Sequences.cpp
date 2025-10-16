static int const MOD = 1'000'000'007;
static int F[51][31][31][16];
static int fact[51];
static int invFact[51];
class Solution {
public:
    int power(int x, int n)
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
    int div(int x)
    {
        return power(x, MOD - 2);
    }
    int magicalSum(int M, int K, vector<int>& nums) {
        int const N = nums.size();
        invFact[0] = fact[0] = 1;
        for (int i = 1; i < 51; ++i)
            fact[i] = 1LL * fact[i - 1] * i % MOD, invFact[i] = div(fact[i]);
        memset(F, 0, sizeof(F));
        F[0][0][0][0] = 1;
        auto add = [](auto& x, auto value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for(int i = 0; i < N; ++i)
            for(int j = 0; j <= M; ++j)
                for(int k = 0; k <= K; ++k)
                    for(int r = 0; 2 * r <= M; ++r)
                        if (F[i][j][k][r])
                            for (int nj = j, f = 1; nj <= M; ++nj, f = 1LL * f * nums[i] % MOD)
                                add(F[i + 1][nj][k + ((r + nj - j) & 1)][(r + nj - j) >> 1], 
                                    1LL * F[i][j][k][r] * f % MOD * invFact[nj - j] % MOD);
        int result = 0;
        for (int k = 0; k <= K; ++k)
            for (unsigned int r = 0; r <= M / 2; ++r)
                if (popcount(r) + k == K)
                    add(result, F[N][M][k][r]);
        return 1LL * result * fact[M] % MOD;
    }
};
