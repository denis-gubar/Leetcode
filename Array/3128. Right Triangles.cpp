class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long result = 0;
        int N = grid.size(), M = grid[0].size();
        vector<int> C(M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                C[j] += grid[i][j];
        for (int i = 0; i < N; ++i)
            for (int k = 0; k < 2; ++k)
            {
                vector<int> A(M + 1);
                for (int j = M - 1; j >= 0; --j)
                    A[j] = A[j + 1] + grid[i][j];
                for (int j = 0; j < M; ++j)
                    if (grid[i][j])
                        result += (C[j] - 1) * A[j + 1];
                reverse(grid[i].begin(), grid[i].end());
                reverse(C.begin(), C.end());
            }
        return result;
    }
};
