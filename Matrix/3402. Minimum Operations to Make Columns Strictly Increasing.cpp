class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        int result = 0;
        for (int j = 0; j < M; ++j)
            for (int i = 1; i < N; ++i)
                if (grid[i][j] < grid[i - 1][j] + 1)
                    result -= grid[i][j] - grid[i - 1][j] - 1, grid[i][j] = grid[i - 1][j] + 1;
        return result;
    }
};
