static long long F[1 << 17];
static int W[17][17];
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        memset(F, 1, sizeof(F));
        F[0] = 0;
        int const N = power.size();
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < N; ++k)
                W[i][k] = (power[i] + k) / (k + 1);
        auto update = [](auto& x, auto value)
            {
                if (x > value)
                    x = value;
            };
        for (int mask = 0; mask < (1 << N); ++mask)
        {
            int k = bitset<17>(mask).count();
            for (int i = 0; i < 17; ++i)
                if ((mask & (1 << i)) == 0)
                    update(F[mask | (1 << i)], F[mask] + W[i][k]);
        }
        return F[(1 << N) - 1];
    }
};
