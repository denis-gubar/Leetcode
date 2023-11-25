static const int MOD = 1'000'000'007;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long x = 0;
        auto calc = [a, b](long long x)
            {
                return __int128(a ^ x) * __int128(b ^ x);
            };
        for (int i = 0; i < n; ++i)
        {
            long long nx = x | (1LL << i);
            if (calc(nx) > calc(x))
                x = nx;
        }
        return calc(x) % MOD;
    }
};