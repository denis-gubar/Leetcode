class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int K) {
        int N = coins.size();
        long long a = 0, b = 1LL << 60;
        auto calc = [&coins, K, N](long long m)
            {
                long long total = 0;
                for (int mask = 1; mask < (1 << N); ++mask)
                {
                    int sum = 0;
                    long long prod = 1;
                    for (int k = 0; k < N; ++k)
                        if (mask & (1 << k))
                            ++sum, prod = lcm(prod, coins[k]);
                    total += m / prod * (sum % 2 * 2 - 1);
                }
                return total >= K;
            };
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
