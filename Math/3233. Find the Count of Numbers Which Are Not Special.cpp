static vector<bool> isPrime(100'000, true);
static vector<int> F;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 100'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 100'000; k += i)
                    isPrime[k] = false;
        F.reserve(10'000);
        for (int i = 2; i * i < 1'000'000'000; ++i)
            if (isPrime[i])
                F.push_back(i * i);
    }
}
class Solution {
public:
    int nonSpecialCount(int L, int R) {
        init();
        return (R - L + 1) - (upper_bound(F.begin(), F.end(), R) - lower_bound(F.begin(), F.end(), L));
    }
};
