static long long fact[17];
static bool isInit = false;
static set<long long> S;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(fact, 0, sizeof(fact));
        fact[0] = fact[1] = 1;
        for (int x = 2; x <= 16; ++x)
            fact[x] = fact[x - 1] * x;
        vector<int> digits;
        string A, t;
        A.reserve(20);
        t.reserve(20);
        for (int mask = 2; mask < 1024; mask += 2)
        {
            int sum = 0;
            int oddCount = 0;
            digits.clear();
            for (int k = 1; k < 10; ++k)
                if (mask & (1 << k))
                    sum += k, digits.push_back(k), oddCount += k % 2;
            if (oddCount > 1 || sum > 16)
                continue;
            A.clear();
            t.clear();
            int odd = 0;
            for (int d : digits)
            {
                if (d % 2 == 1)
                    odd = d;
                for (int x = 0; x < d / 2; ++x)
                    A += (d + '0');
            }
            do
            {
                t = A;
                if (odd)
                    t += (odd + '0');
                copy(A.rbegin(), A.rend(), back_inserter(t));
                S.insert(stoll(t));
            } while (next_permutation(A.begin(), A.end()));
        }
    }
}
class Solution {
public:
    long long specialPalindrome(long long N) {
        init();
        return *S.upper_bound(N);
    }
};
