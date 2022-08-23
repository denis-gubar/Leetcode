class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> result(N - 2, vector<int>(N - 2));
        for(int i = 0; i < N - 2; ++i)
            for (int j = 0; j < N - 2; ++j)
            {
                result[i][j] = grid[i][j];
                for (int dx = 0; dx < 3; ++dx)
                    for (int dy = 0; dy < 3; ++dy)
                        result[i][j] = max(result[i][j], grid[i + dx][j + dy]);
            }
        return result;
    }
};
