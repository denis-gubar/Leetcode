static int F[1'001][102][2];
class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        int const N = prices.size();
        memset(F, -100, sizeof(F));
        int const INF = F[0][0][0];
        F[0][0][0] = 0;
        auto update = [](int& x, int value)
            {
                if (x < value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j <= K; ++j)
            {
                update(F[i + 1][j][0], F[i][j][0]);
                update(F[i + 1][j][1], F[i][j][1]);
                update(F[i + 1][j + 1][1], F[i][j][0] - prices[i]);
                update(F[i + 1][j][0], F[i][j][1] + prices[i]);
            }
        int result = 0;
        for (int j = 1; j <= K; ++j)
            update(result, F[N][j][0]);
        return result;
    }
};
