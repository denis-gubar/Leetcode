int static primes[1'000];
int static F[1'001];
int static primeCount = 0;
bool static isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        vector<bool> isPrime(1'001, 1);
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 1'000'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k <= 1'000; k += i)
                    isPrime[k] = 0;
        for (int i = 2; i < 1'000; ++i)
            if (isPrime[i])
                primes[primeCount] = i, ++primeCount;
        F[0] = 0;
    }
}
class Solution {
public:
    int minNumberOfPrimes(int N, int M) {
        init();
        M = min(M, primeCount);
        memset(F, -1, sizeof(F));
        F[0] = 0;
        auto update = [](int& x, int value)
            {
                if (value == 0)
                    return;
                if (x == -1 || x > value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M && primes[j] + i <= N; ++j)
                update(F[i + primes[j]], F[i] + 1);
        return F[N];
    }
};
