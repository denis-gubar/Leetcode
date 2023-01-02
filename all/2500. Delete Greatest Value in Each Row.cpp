class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int result = 0;
        int N = grid.size(), M = grid[0].size();
        for (int i = 0; i < N; ++i)
            sort(grid[i].begin(), grid[i].end());
        for (int j = 0; j < M; ++j)
        {
            int k = 0;
            for (int i = 0; i < N; ++i)
                k = max(k, grid[i][j]);
            result += k;
        }
        return result;
    }
};
