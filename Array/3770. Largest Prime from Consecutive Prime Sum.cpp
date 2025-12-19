static int primes[500'001];
static int P[10'001];
static int COUNT = 0;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(primes, 0, sizeof(primes));
        static vector<bool> isPrime(500'001, 1);
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 500'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 500'001; k += i)
                    isPrime[k] = 0;
        P[COUNT] = 0, ++COUNT;
        int total = 0;
        for (int i = 2; i < 500'001; ++i)
            if (isPrime[i])
            {
                total += i;
                if (total > 500'000)
                    break;
                if (isPrime[total])
                    P[COUNT] = total, ++COUNT;
            }
        P[COUNT] = 500'001;
        ++COUNT;
    }
}
class Solution {
public:
    int largestPrime(int N) {
        init();
        auto it = upper_bound(&P[0], &P[0] + COUNT, N);
        return *prev(it);
    }
};
