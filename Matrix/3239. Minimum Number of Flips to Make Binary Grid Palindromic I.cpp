class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        int result1 = 0;
        for (int i = 0; i < N; ++i)
            for (int a = 0, b = M - 1; a < b; ++a, --b)
                result1 += grid[i][a] != grid[i][b];
        int result2 = 0;
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            for (int j = 0; j < M; ++j)
                result2 += grid[a][j] != grid[b][j];
        return min(result1, result2);
    }
};
