static int F[10'001];
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(F, -1, sizeof(F));
        auto update = [](int& x, int value)
            {
                if (x < 0 || x > value)
                    x = value;
            };
        F[0] = 0;
        for (int c : coins)
            for (int i = 0; i + c <= amount; ++i)
                if (F[i] >= 0)
                    update(F[i + c], F[i] + 1);
        return F[amount];
    }
};
