class Solution {
public:
    const int MOD = 1'000'000'007;
    int result;
    void calc(vector<int> const& M, vector<int> const& divs, int mask, int last, int count)
    {
        if (!count)
            return;
        if (last > 1)
            result = (result + count) % MOD;
        for (int next = last + 1; next <= 30; ++next)
            if (M[next] && (divs[next] & mask) == 0)
                calc(M, divs, mask | divs[next], next, 1LL * count * M[next] % MOD);
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        result = 0;
        vector<int> M(31);
        for (int x : nums)
            ++M[x];
        long long A = 1;
        for (int x = 0; x < M[1]; ++x)
            A = (A + A) % MOD;
        vector<bool> isPrime(31, true);
        isPrime[1] = isPrime[0] = false;
        vector<int> P(31), divs(31);
        int primeCount = 0;
        for (int i = 2; i < 30; ++i)
            if (isPrime[i])
            {
                for (int k = i * i; k < 30; k += i)
                    isPrime[k] = false;
                P[i] = ++primeCount;
            }
        for (int x = 2; x <= 30; ++x)
            for (int y = 2; y <= x; ++y)
                if (isPrime[y] && x % y == 0)
                {
                    if (x % (y * y) == 0)
                    {
                        M[x] = 0;
                        break;
                    }
                    divs[x] |= 1 << P[y];
                }
        calc(M, divs, 0, 1, 1);
        return result * A % MOD;
    }
};
