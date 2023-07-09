class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> result(M);
        for (int j = 0; j < M; ++j)
            for (int i = 0; i < N; ++i)
                result[j] = max<int>(result[j], to_string(grid[i][j]).size());
        return result;
    }
};
