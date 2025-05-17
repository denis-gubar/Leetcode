static long long F[5'001];
static long long INF = 1LL << 32;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        memset(F, 0, sizeof(F));
        F[0] = 1;
        auto add = [](long long& x, long long value)
            {
                x += value;
                if (x > INF)
                    x = INF;
            };
        for (int c : coins)
            for (int i = 0; i <= amount - c; ++i)
                add(F[i + c], F[i]);
        return F[amount];
    }
};
