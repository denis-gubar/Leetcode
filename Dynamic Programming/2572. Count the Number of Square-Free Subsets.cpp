static int const MOD = 1'000'000'007;
static array const A{ 2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30 };
static int const maskCount = 6'655;
static int masks[maskCount];
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        vector<int> X;
        X.reserve(18);
        int i = 0;
        for (int mask = 1; mask < (2 << 18); ++mask)
        {
            X.clear();
            bool flag = true;
            for (int k = 0; k < 18; ++k)
                if (mask & (1 << k))
                {

                    for (int x : X)
                        if (gcd(x, A[k]) > 1)
                        {
                            flag = false;
                            break;
                        }
                    if (!flag)
                        break;
                    X.push_back(A[k]);
                }
            if (flag)
                masks[i] = mask, ++i;
        }
    }
}
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {        
        init();
        vector<int> M(31);
        for (int x : nums)
            ++M[x];
        long long result = 0;
        int goodMask = 0;
        for (int i = 0; i < 18; ++i)
            if (M[A[i]] > 0)
                goodMask |= 1 << i;
        for (int mask : masks)
        {
            if ((goodMask & mask) < mask)
                continue;
            int current = 1;
            for (int k = 0; k < 18; ++k)
                if (mask & (1 << k))
                    current = 1LL * current * M[A[k]] % MOD;
            result += current;
        }
        result %= MOD;
        int x = 1;
        for (int i = 0; i < M[1]; ++i)
        {
            result <<= 1;
            if (result >= MOD)
                result -= MOD;
            x <<= 1;
            if (x > MOD)
                x -= MOD;
        }
        result += x - 1 + MOD;
        result %= MOD;
        return result;
    }
};
