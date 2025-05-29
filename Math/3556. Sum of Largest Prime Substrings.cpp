static bool isInit = false;
static int primes[100'000];
static vector<bool> isPrime(100'001, 1);
static int primeCount = 0;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(primes, 0, sizeof(primes));
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 100'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 100'001; k += i)
                    isPrime[k] = 0;
        for (int i = 2; i < 100'001; ++i)
            if (isPrime[i])
            {
                primes[primeCount] = i;
                ++primeCount;
            }
    }
}
class Solution {
public:
    bool calc(long long x)
    {
        if (x < 100'000)
            return isPrime[x];
        for (int i = 0; i < primeCount; ++i)
            if (x % primes[i] == 0)
                return false;
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        init();
        long long result = 0;
        int const N = s.size();
        set<long long> S;
        for (int start = 0; start < N; ++start)
        {
            long long value = 0;
            for (int length = 1; length + start <= N; ++length)
            {
                value = value * 10 + (s[start + length - 1] - '0');
                if ((S.size() < 3 || *S.begin() < value) && calc(value))
                {
                    S.insert(value);
                    if (S.size() > 3)
                        S.erase(S.begin());
                }
            }
        }
        for (long long x : S)
            result += x;
        return result;
    }
};
