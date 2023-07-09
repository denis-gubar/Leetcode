int static primes[100'000];
int static primeCount = 0;
bool static isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        vector<bool> isPrime(1'000'000, 1);
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 1'000'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 1'000'000; k += i)
                    isPrime[k] = 0;
        for (int i = 2; i < 1'000'000; ++i)
            if (isPrime[i])
                primes[primeCount] = i, ++primeCount;
        primes[primeCount] = 1'000'001;
    }
}
class Solution {
public:
    vector<vector<int>> findPrimePairs(int N) {
        init();
        vector<vector<int>> result;
        result.reserve(N / 2);
        for (int L = 0; L < primeCount && primes[L] <= N - primes[L]; ++L)
        {
            if (binary_search(&primes[0], &primes[primeCount], N - primes[L]))
                result.push_back({ primes[L], N - primes[L] });
        }
        return result;
    }
};
