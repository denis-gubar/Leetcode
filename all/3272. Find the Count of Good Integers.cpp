static int digits[10];
static int fact[11];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        fact[0] = fact[1] = 1;
        for (int x = 2; x <= 10; ++x)
            fact[x] = 1LL * fact[x - 1] * x;
    }
}
class Solution {
public:
    long long countGoodIntegers(int N, int K) {
        init();
        long long result = 0;
        int const L = (N - 1) / 2, R = N / 2;
        int x = 1;
        for (int i = 0; i < L; ++i)
            x *= 10;
        set<string> S;
        for (int i = x, end = x * 10; i < end; ++i)
        {
            long long x = i;
            int j = i;
            if (L == R)
                j /= 10;
            for (int i = 0; i < R; ++i)
                x = x * 10 + j % 10, j /= 10;
            if (x % K != 0)
                continue;
            string s = to_string(x);
            sort(s.begin(), s.end());
            if (!S.insert(s).second)
                continue;
            memset(digits, 0, sizeof(digits));
            for (int i = 0; i < N; ++i)
                ++digits[x % 10], x /= 10;
            long long current = fact[N];
            for (int d = 0; d < 10; ++d)
                current /= fact[digits[d]];
            if (digits[0] > 0)
            {
                long long delta = fact[N - 1] / fact[digits[0] - 1];
                for (int d = 1; d < 10; ++d)
                    delta /= fact[digits[d]];
                current -= delta;
            }
            result += current;
        }
        return result;
    }
};
