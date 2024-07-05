static vector<int> F;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        vector<bool> isPrime(10'000, true);
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 10'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 10'000; k += i)
                    isPrime[k] = false;
        vector<int> primes;
        primes.reserve(1'300);
        for (int i = 2; i < 10'000; ++i)
            if (isPrime[i])
                primes.push_back(i);
        F.reserve(800);
        F.push_back(2);
        F.push_back(3);
        F.push_back(5);
        F.push_back(7);
        for (int prefix = 1; prefix < 10'000; ++prefix)
        {
            int rest = prefix;
            int suffix = 0, k = 1;
            while (rest > 0)
            {
                suffix = suffix * 10 + rest % 10;
                rest /= 10;
                k *= 10;
            }
            auto add = [&primes](int x)
                {
                    for (int i = 0; primes[i] * primes[i] <= x; ++i)
                        if (x % primes[i] == 0)
                            return;
                    if (x == 10301)
                        cout << "found
";
                    F.push_back(x);
                };
            add(prefix * k + suffix);
            if (prefix < 1'000)
                for (int d = 0; d < 10; ++d)
                    add(k * (prefix * 10 + d) + suffix);
        }
        F.push_back(100'030'001);
        sort(F.begin(), F.end());
    }
}
class Solution {
public:
    int primePalindrome(int n) {
        init();
        return *lower_bound(F.begin(), F.end(), n);
    }
};
