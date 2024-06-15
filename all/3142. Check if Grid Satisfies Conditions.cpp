class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (i + 1 < N && grid[i][j] != grid[i + 1][j])
                    return false;
                if (j + 1 < M && grid[i][j] == grid[i][j + 1])
                    return false;
            }
        return true;
    }
};
