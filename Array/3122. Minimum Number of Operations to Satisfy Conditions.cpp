int static F[1'001][10];
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        memset(F, 1, sizeof(F));
        for(int j = 0; j < 10; ++j)
            F[M][j] = 0;
        for (int i = M - 1; i >= 0; --i)
        {
            vector<int> A(10);
            for (int j = 0; j < N; ++j)
                ++A[grid[j][i]];
            for (int a = 0; a < 10; ++a)
                for (int b = 0; b < 10; ++b)
                    if (a != b)
                        F[i][a] = min(F[i][a], F[i + 1][b] + N - A[a]);
        }
        int result = 1 << 30;
        for (int j = 0; j < 10; ++j)
            result = min(result, F[0][j]);
        return result;
    }
};
