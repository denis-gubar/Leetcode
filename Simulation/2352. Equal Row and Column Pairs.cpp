class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int N = grid.size();
        int result = 0;
        vector<vector<int>> cols(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cols[i][j] = grid[j][i];
        sort(cols.begin(), cols.end());
        for (int i = 0; i < N; ++i)
        {
            auto p = equal_range(cols.begin(), cols.end(), grid[i]);
            result += p.second - p.first;
        }
        return result;
    }
};
