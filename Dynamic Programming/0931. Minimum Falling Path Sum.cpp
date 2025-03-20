static short F[100][100];
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int const N = matrix.size();
        memset(F, 100, sizeof(F));
        for (int j = 0; j < N; ++j)
            F[0][j] = matrix[0][j];
        for(int i = 1; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                if (j > 0)
                    F[i][j] = min<short>(F[i][j], F[i - 1][j - 1] + matrix[i][j]);
                F[i][j] = min<short>(F[i][j], F[i - 1][j] + matrix[i][j]);
                if (j < N - 1)
                    F[i][j] = min<short>(F[i][j], F[i - 1][j + 1] + matrix[i][j]);
            }
        return *min_element(&F[N - 1][0], &F[N - 1][0] + N);
    }
};
