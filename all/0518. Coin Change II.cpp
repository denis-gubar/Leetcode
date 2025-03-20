static long long F[5'001];
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int const N = coins.size();
        memset(F, 0, sizeof(F));
        F[0] = 1;
        for (int c : coins)
            for (int i = 0; i <= amount - c; ++i)
            {
                F[i + c] += F[i];
                F[i + c] %= 1LL << 32;
            }
        return F[amount];
    }
};
