class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int result = 0;
        vector<vector<int>> F(N, vector<int>(M));
         for (int j = M - 1; j > 0; --j)
            for(int i = 0; i < N; ++i)
            {
                if (i > 0 && grid[i][j] > grid[i - 1][j - 1])
                    F[i - 1][j - 1] = max(F[i - 1][j - 1], F[i][j] + 1);
                if (grid[i][j] > grid[i][j - 1])
                    F[i][j - 1] = max(F[i][j - 1], F[i][j] + 1);
                if (i < N - 1 && grid[i][j] > grid[i + 1][j - 1])
                    F[i + 1][j - 1] = max(F[i + 1][j - 1], F[i][j] + 1);
            }
        for (int i = 0; i < N; ++i)
            result = max(result, F[i][0]);
        return result;
    }
};
