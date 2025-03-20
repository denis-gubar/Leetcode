static int F[5'001][3];
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int const N = prices.size();
        memset(F, -100, sizeof(F));
        int const INF = F[0][0];
        F[0][0] = 0;
        auto update = [](int& x, int value)
            {
                if (x < value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
        {
            update(F[i + 1][0], F[i][0]);
            update(F[i + 1][1], F[i][1]);
            update(F[i + 1][0], F[i][2]);
            update(F[i + 1][1], F[i][0] - prices[i]);
            update(F[i + 1][2], F[i][1] + prices[i]);
        }
        return max(F[N][0], F[N][2]);
    }
};
