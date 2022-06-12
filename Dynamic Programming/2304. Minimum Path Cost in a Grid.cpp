class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {        
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N + 1, vector<int>(M, 1 << 30));
        for (int i = 0; i < M; ++i)
            F[0][i] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                for (int k = 0; k < M; ++k)
                    F[i + 1][k] = min(F[i + 1][k], F[i][j] + grid[i][k] + (i > 0 ? moveCost[grid[i - 1][j]][k] : 0));
        return *min_element(F[N].begin(), F[N].end());
    }
};
