static int F[101][20][102];
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int N, int K, int target) {
        memset(F, -1, sizeof(F));
        F[0][0][0] = 0;
        auto update = [](int& x, int value)
            {
                if (x < 0 || x > value)
                    x = value;
            };
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j)
            {
                for (int k = 0; k <= min(target, i); ++k)
                    if (F[i][j][k] >= 0)
                    {
                        for (int nj = 0; nj < K; ++nj)
                        {
                            if (houses[i] > 0 && houses[i] != nj + 1)
                                continue;
                            int delta = (houses[i] == nj + 1) ? 0 : cost[i][nj];
                            update(F[i + 1][nj][k + (j != nj || i == 0)], F[i][j][k] + delta);
                        }
                        if (i == 0)
                            break;
                    }
                if (i == 0)
                    break;
            }
        int result = -1;
        for (int j = 0; j < K; ++j)
            if (F[N][j][target] >= 0)
                update(result, F[N][j][target]);
        return result;
    }
};
