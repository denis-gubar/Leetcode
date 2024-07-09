class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int result = 0;
        int const N = grid.size();
        int const M = grid[0].size();
        vector<vector<int>> X(N, vector<int>(M));
        vector<vector<int>> Y(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
            int totalRowX = 0;
            int totalRowY = 0;
            for (int j = 0; j < M; ++j)
            {
                totalRowX += grid[i][j] == 'X';
                totalRowY += grid[i][j] == 'Y';
                X[i][j] += (i > 0 ? X[i - 1][j] : 0) + totalRowX;
                Y[i][j] += (i > 0 ? Y[i - 1][j] : 0) + totalRowY;
            }
        }
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                result += (X[i][j] == Y[i][j] && X[i][j] > 0);
        return result;
    }
};
