class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        vector<vector<int>> F(N + 1, vector<int>(N + 1, 1000 * N));
        F[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for(int x = min(N / 2, i), y = i - x; x >= 0; --x, ++y)
            {
                F[x + 1][y] = min(F[x + 1][y], F[x][y] + costs[i][0]);
                F[x][y + 1] = min(F[x][y + 1], F[x][y] + costs[i][1]);
            }
        return F[N / 2][N / 2];
    }
};