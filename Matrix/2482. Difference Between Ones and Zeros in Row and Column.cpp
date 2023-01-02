class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> result(N, vector<int>(M));
        vector<int> oneRow(N), zeroRow(N);
        vector<int> oneCol(M), zeroCol(M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == 0)
                    ++zeroRow[i], ++zeroCol[j];
                else
                    ++oneRow[i], ++oneCol[j];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                result[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
        return result;
    }
};
